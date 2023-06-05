#!/usr/bin/python3

import json
import re
from pathlib import Path
import argparse
import logging

from FuncSignature import FuncSignature

logger = logging.getLogger(__name__)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-f", "--force", action="store_true", help="Overwrite existing files.")
    parser.add_argument('-l', '--language', help='The language to use')  # list available languages
    parser.add_argument("params", help="The json data from bookmarklet")
    args = parser.parse_args()

    # cleaning first
    params = json.loads(args.params)
    params["code"] = re.sub(r"\xa0", " ", params["code"])  # replace &nbsp; to ' '

    # import languages specific functions
    from languages.cpp import *

    filename = get_file_name(params["title"])
    filepath = get_file_path(params["level"], filename)
    if not args.force and filepath.exists():
        logger.fatal("destination(%s) exists. use -f to overwrite." % filepath)
        exit(1)

    # create dir(Easy/Medium/Hard) to store generated code file
    Path(params["level"]).mkdir(exist_ok=True)

    func_signature: FuncSignature = extract_func_signature(params["code"])
    with open(filepath, "w") as f:
        f.write(render(func_signature, params))
        print("written to file %s" % filepath.name)
    post_render()
