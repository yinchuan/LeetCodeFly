import re
import logging
from pathlib import Path

from lib.abstract_render import AbstractRender
from lib.FuncSignature import FuncSignature

logger = logging.getLogger(__name__)


class Render(AbstractRender):
    def extract_func_signature(self) -> FuncSignature:
        # extract function name, return type, parameters
        match = re.findall("([\w\<\>\*]+) ([\w\<\>]+)\((.*)\)", self.params["code"])
        if not match:
            logger.error("fail to extrac function signature.")
            return FuncSignature('', '', [])

        return FuncSignature(
            match[0][1],
            match[0][0],
            [p.strip().split(' ') for p in match[0][2].split(",")]
        )

    def get_file_name(self) -> str:
        return (self.params["title"]
                .replace(')', '_')
                .replace('.', '')
                .replace(' ', '_')
                .replace(',', '')
                .replace('(', '_')
                .replace(')', '_') + ".cpp")

    def get_file_path(self) -> Path:
        # put file in <level>/filename
        return Path(self.params["level"]) / self.get_file_name()

    def render(self) -> str:
        func_signature: FuncSignature = self.extract_func_signature()
        result: str = ""

        # include library which could be used, will not be copied to LeetCode
        includes = ['iostream', 'vector', 'algorithm', 'string', 'map', 'set', 'unordered_map', 'stack', 'numeric',
                    'queue', 'cmath']
        custom_includes = ["ListNode.h", "TreeNode.h", "utils.h"]

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
        result += "// %s\n" % self.params["url"]

        # includes
        for include in includes:
            result += "#include <%s>\n" % include

        for include in custom_includes:
            result += "#include \"../lib/%s\"\n" % include

        result += "using namespace std;\n"
        result += separator + "\n"

        # base code from LeetCode
        result += self.params["code"]

        # driver
        result += "\n"
        result += separator + "\n"
        result += driver

        return result

    def post_render(self, src_root: Path) -> None:
        # add new executable, example: add_executable(1528_Shuffle_String Easy/1528_Shuffle_String.cpp)
        with open(src_root / Path("CMakeLists.txt"), 'a') as f:
            f.write("\nadd_executable(%s %s)" % (self.get_file_name().split(".")[0], self.get_file_path()))
