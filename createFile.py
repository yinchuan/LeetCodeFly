#!/usr/bin/python3

import json
import re
from pathlib import Path
import argparse
import logging

logger = logging.getLogger(__name__)


class FuncSignature:
    def __init__(self, name: str, return_type: str, parameter: [(str, str)]):
        self.name = name
        self.return_type = return_type
        self.parameter = parameter  # (type, name)

    def gen_parameter_declaration(self) -> str:
        # result example: int a; string c;
        return ";\n".join(["%s %s" % (p[0].replace('&', ''), p[1]) for p in self.parameter])

    def gen_parameter_init(self) -> str:
        return "=;\n".join([p[1] for p in self.parameter])

    def gen_parameter_pass_in(self) -> str:
        return ", ".join([p[1] for p in self.parameter])


def generate(filepath: Path, func_signature: FuncSignature, params) -> None:
    # include library which could be used, will not be copied to LeetCode
    includes = ['iostream', 'vector', 'algorithm', 'string', 'map']

    driver = '''
    //===== do not copy lines after this to LeetCode
    int main() {
        Solution sol;
        %s ans;
        %s;

        %s;
        ans = sol.%s(%s);
        std::cout << ans << std::endl;
    }
    ''' % (func_signature.return_type,
           func_signature.gen_parameter_declaration(),
           func_signature.gen_parameter_init(),
           func_signature.name,
           func_signature.gen_parameter_pass_in()
           )

    # only lines between separator need to be copied back to LeetCode for submit
    separator = "//#####"

    # @todo convert to a template?
    with open(filepath, 'w') as f:
        # url on LeetCode
        f.write("// %s\n" % params["url"])

        # includes
        for include in includes:
            f.write("#include <%s>\n" % include)

        f.write(separator + "\n")
        f.write("using namespace std;\n")

        # base code from LeetCode
        f.write(re.sub(r"\xa0", " ", params["code"]))  # replace &nbsp; to ' '

        # driver
        f.write("\n")
        f.write(separator + "\n")
        f.write(driver)

    print("written to file %s" % filepath.name)

    # add new executable, example: add_executable(1528_Shuffle_String Easy/1528_Shuffle_String.cpp)
    with open(Path("CMakeLists.txt"), 'a') as f:
        f.write("\nadd_executable(%s %s)" % (filename, filepath))


def get_file_path(level: str, title: str, type: str = "cpp") -> (str, Path):
    # put file in <level>/<title>.type
    filename: str = title.replace('.', '').replace(' ', '_')
    filepath: Path = Path(level) / Path("%s.%s" % (filename, type))
    return filename, filepath


def extract_func_signature(code: str) -> FuncSignature:
    # extract function name, return type, parameters
    code = re.sub(r"\xa0", " ", params["code"]).replace("\n", "")
    match = re.findall("(\w+) (\w+)\((.*)\)", code)
    if not match:
        logging.error("fail to extrac function signature.")
        return FuncSignature('', '', [])

    return FuncSignature(
        match[0][1],
        match[0][0],
        [p.strip().split(' ') for p in match[0][2].split(",")]
    )


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-f", "--force", action="store_true", help="Overwrite existing files.")
    parser.add_argument("params", help="The json data from bookmarklet")
    args = parser.parse_args()

    params = json.loads(args.params)
    code = re.sub(r"\xa0", " ", params["code"])  # replace &nbsp; to ' '

    filename, filepath = get_file_path(params["level"], params["title"], "cpp")
    if not args.force and filepath.exists():
        logging.fatal("destination(%s) exists. use -f to overwrite." % filepath)
        exit(1)

    # create dir(Easy/Medium/Hard) to store generated code file
    Path(params["level"]).mkdir(exist_ok=True)

    func_signature = extract_func_signature(params["code"])

    generate(filepath, func_signature, params)
