"""This script generates the XAP protocol generated header to be compiled into QMK.
"""
import re

from qmk.path import normpath
from qmk.commands import get_git_version
from qmk.xap.common import latest_xap_defs
from qmk.constants import GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE


def _append_defines(lines, route_container, name_stack=[]):
    name_stack.append(route_container['define'].upper())
    for route_id in route_container['routes']:
        route = route_container['routes'][route_id]
        name_stack.append(route['define'].upper())
        name_stack_str = ('_'.join(name_stack)).upper()
        if route['type'] == 'router':
            route_name = route['name']
            lines.append(f'//----------------------------------------------------------------')
            lines.append(f'// Subsystem: {route_name}')
            if 'enable_if_preprocessor' in route:
                condition = route['enable_if_preprocessor']
                lines.append(f'#if {condition}')
            lines.append(f'#define {name_stack_str} {route_id}')
            lines.append(f'#define {name_stack_str}_MASK (1ul << ({name_stack_str}))')
            lines.append('')
            _append_defines(lines, route, name_stack[:-1])
            if 'enable_if_preprocessor' in route:
                lines.append(f'#endif  // {condition}')
            lines.append('')
        elif route['type'] == 'command':
            lines.append(f'#define {name_stack_str} {route_id}')
            lines.append(f'#define {name_stack_str}_MASK (1ul << ({name_stack_str}))')
        name_stack.pop()
    name_stack.pop()


def generate_header(output_file):
    """Generates the XAP protocol header file, generated during normal build.
    """
    xap_defs = latest_xap_defs()

    # Preamble
    lines = [GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE, '#pragma once', '']

    # Versions
    prog = re.compile(r'^(\d+)\.(\d+)\.(\d+)')
    b = prog.match(xap_defs['version'])
    lines.append(f'#define XAP_BCD_VERSION 0x{int(b.group(1)):02d}{int(b.group(2)):02d}{int(b.group(3)):04d}')
    b = prog.match(get_git_version())
    lines.append(f'#define QMK_BCD_VERSION 0x{int(b.group(1)):02d}{int(b.group(2)):02d}{int(b.group(3)):04d}')
    lines.append('')

    # Append the route and command defines
    _append_defines(lines, xap_defs)
    lines.append('')

    xap_generated_inl = '\n'.join(lines)

    if output_file:
        if output_file.name == '-':
            print(xap_generated_inl)
        else:
            output_file.parent.mkdir(parents=True, exist_ok=True)
            if output_file.exists():
                output_file.replace(output_file.parent / (output_file.name + '.bak'))
            output_file.write_text(xap_generated_inl)
