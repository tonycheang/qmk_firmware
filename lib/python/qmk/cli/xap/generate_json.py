"""This script generates the XAP protocol documentation.
"""
import hjson
from milc import cli
from qmk.xap.common import latest_xap_defs

@cli.subcommand('Generates the XAP protocol documentation.', hidden=False if cli.config.user.developer else True)
def xap_generate_json(cli):
    """Generates the consolidated XAP protocol definitions.
    """
    defs = latest_xap_defs()
    print(hjson.dumps(defs))