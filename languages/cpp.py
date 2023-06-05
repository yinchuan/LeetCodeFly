import re
import logging
from pathlib import Path

from FuncSignature import FuncSignature

logger = logging.getLogger(__name__)


def extract_func_signature(code: str) -> FuncSignature:
    # extract function name, return type, parameters
    code = re.sub(r"\xa0", " ", code).replace("\n", "")
    match = re.findall("(\w+) (\w+)\((.*)\)", code)
    if not match:
        logger.error("fail to extrac function signature.")
        return FuncSignature('', '', [])

    return FuncSignature(
        match[0][1],
        match[0][0],
        [p.strip().split(' ') for p in match[0][2].split(",")]
    )


def get_file_name(title: str) -> str:
    return title.replace('.', '').replace(' ', '_') + ".cpp"


def get_file_path(level: str, filename: str) -> Path:
    # put file in <level>/filename
    return Path(level) / filename


def render(func_signature: FuncSignature, params) -> str:
    result: str = ""

    # include library which could be used, will not be copied to LeetCode
    includes = ['iostream', 'vector', 'algorithm', 'string', 'map']

    driver = '''
    // do not copy lines after this to LeetCode
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

    # url on LeetCode
    result += "// %s\n" % params["url"]

    # includes
    for include in includes:
        result += "#include <%s>\n" % include

    result += separator + "\n"
    result += "using namespace std;\n"

    # base code from LeetCode
    result += params["code"]

    # driver
    result += "\n"
    result += separator + "\n"
    result += driver

    return result


def post_render() -> None:
    pass
    # add new executable, example: add_executable(1528_Shuffle_String Easy/1528_Shuffle_String.cpp)
    # with open(Path("CMakeLists.txt"), 'a') as f:
    #     f.write("\nadd_executable(%s %s)" % (filename, filepath))
