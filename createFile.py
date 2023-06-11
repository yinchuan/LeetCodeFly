#!/usr/bin/python3
# @todo add pytest

import json
import re
from pathlib import Path
import argparse
import logging

logger = logging.getLogger(__name__)


def get_supported_langs() -> [str]:
    return [f.stem for f in Path("languages").glob("*") if f.is_file()]


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-f", "--force", action="store_true", help="Overwrite existing files.")
    parser.add_argument('-l', '--language', default='cpp',
                        help='The language to use: %s. default: cpp' % "|".join(get_supported_langs()))
    parser.add_argument("-r", "--root", default=".",
                        help="the root directory to store generated code files. default: '.'")
    parser.add_argument("params", help="The json data from bookmarklet")
    args = parser.parse_args()

    # import languages specific render
    try:
        language = __import__("languages.%s" % args.language, fromlist=["languages"])
    except ImportError as e:
        logger.fatal("not supported language: %s" % args.language)
        logger.error(e.msg)
        exit(1)

    # cleaning first
    params = json.loads(args.params)
    params["code"] = re.sub(r"\xa0", " ", params["code"])  # replace &nbsp; to ' '

    render = language.Render(params)
    filepath = Path(args.root) / render.get_file_path()
    if not args.force and filepath.exists():
        logger.fatal("destination(%s) exists. use -f to overwrite." % filepath)
        exit(1)

    # create dir(Easy/Medium/Hard) to store generated code file
    filepath.parent.mkdir(exist_ok=True)

    with open(filepath, "w") as f:
        f.write(render.render())
        print("written to file %s" % filepath)
    render.post_render(args.root)
