"""This script generates the XAP protocol generated header to be compiled into QMK.
"""
import re
import pyhash

from qmk.commands import get_git_version
from qmk.constants import GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE
from qmk.xap.common import latest_xap_defs


def _route_conditions(route_stack):
    """Handles building the C preprocessor conditional based on the current route.
    """
    conditions = []
    for route in route_stack:
        if 'enable_if_preprocessor' in route:
            conditions.append(route['enable_if_preprocessor'])

    if len(conditions) == 0:
        return None

    return "(" + ' && '.join([f'({c})' for c in conditions]) + ")"


def _append_route_defines(lines, container, route_stack=[]):
    """Handles building the list of the XAP routes, combining parent and child names together, as well as the route number.
    """
    if 'routes' in container:
        for route_id in container['routes']:
            route = container['routes'][route_id]
            route_stack.append(route)
            route_name = '_'.join([r['define'] for r in route_stack])
            lines.append(f'#define XAP_ROUTE_{route_name} {route_id}')
            _append_route_defines(lines, route, route_stack)
            route_stack.pop()


def _append_route_masks(lines, container, route_stack=[]):
    """Handles creating the equivalent XAP route masks, for capabilities checks. Forces value of `0` if
    """
    if 'routes' in container:
        for route_id in container['routes']:
            route = container['routes'][route_id]
            route_stack.append(route)
            route_name = '_'.join([r['define'] for r in route_stack])

            condition = _route_conditions(route_stack)
            if condition:
                lines.append('')
                lines.append(f'#if {condition}')

            lines.append(f'#define XAP_ROUTE_{route_name}_MASK (1ul << (XAP_ROUTE_{route_name}))')

            if condition:
                lines.append(f'#else  // {condition}')
                lines.append(f'#define XAP_ROUTE_{route_name}_MASK 0')
                lines.append(f'#endif  // {condition}')
                lines.append('')

            _append_route_masks(lines, route, route_stack)

            route_stack.pop()


def _append_route_capabilities_masks(lines, container, route_stack=[]):
    if 'routes' in container:
        for route_id in container['routes']:
            route = container['routes'][route_id]
            route_stack.append(route)

            route_name = '_'.join([r['define'] for r in route_stack])
            lines.append(f'  | (XAP_ROUTE_{route_name}_MASK) \\')
            route_stack.pop()


def _append_route_capabilities(lines, container, route_stack=[]):
    if 'routes' in container:
        for route_id in container['routes']:
            route = container['routes'][route_id]
            if route['type'] != 'router':
                continue
            route_stack.append(route)
            route_name = '_'.join([r['define'] for r in route_stack])

            lines.append(f'#define XAP_ROUTE_{route_name}_CAPABILITIES (0 \\')
            if 'routes' in route:
                _append_route_capabilities_masks(lines, route, route_stack)
            lines.append('  )')
            lines.append('')

            _append_route_capabilities(lines, route, route_stack)

            route_stack.pop()


def generate_header(output_file, keyboard):
    """Generates the XAP protocol header file, generated during normal build.
    """
    xap_defs = latest_xap_defs()

    # Preamble
    lines = [GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE, '#pragma once', '']

    # Versions
    prog = re.compile(r'^(\d+)\.(\d+)\.(\d+)')
    b = prog.match(xap_defs['version'])
    lines.append(f'#define XAP_BCD_VERSION 0x{int(b.group(1)):02d}{int(b.group(2)):02d}{int(b.group(3)):04d}ul')
    b = prog.match(get_git_version())
    lines.append(f'#define QMK_BCD_VERSION 0x{int(b.group(1)):02d}{int(b.group(2)):02d}{int(b.group(3)):04d}ul')
    keyboard_id = pyhash.mum_64()(keyboard)
    lines.append(f'#define XAP_KEYBOARD_IDENTIFIER 0x{keyboard_id:016X}ull')
    lines.append('')

    # Append the route and command defines
    _append_route_defines(lines, xap_defs)
    lines.append('')
    _append_route_masks(lines, xap_defs)
    lines.append('')
    _append_route_capabilities(lines, xap_defs)
    lines.append(f'#define XAP_CAPABILITIES (0 \\')
    _append_route_capabilities_masks(lines, xap_defs)
    lines.append('  )')
    lines.append('')

    # Generate the full output
    xap_generated_inl = '\n'.join(lines)

    # Clean up newlines
    while "\n\n\n" in xap_generated_inl:
        xap_generated_inl = xap_generated_inl.replace("\n\n\n", "\n\n")

    if output_file:
        if output_file.name == '-':
            print(xap_generated_inl)
        else:
            output_file.parent.mkdir(parents=True, exist_ok=True)
            if output_file.exists():
                output_file.replace(output_file.parent / (output_file.name + '.bak'))
            output_file.write_text(xap_generated_inl)
