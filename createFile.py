import json
import sys
import re
from pathlib import Path

params = json.loads(sys.argv[1])

# will put file in <level>/<title>.cpp
Path(params["level"]).mkdir(exist_ok=True)
filename = params["title"].replace('.', '').replace(' ', '_')
filepath = Path(params["level"]) / Path("%s.%s" % (filename, "cpp"))

# include library which could be used, will not be copied to LeetCode
includes = ['iostream', 'vector', 'algorithm', 'string', 'map']

driver = '''
//===== do not copy lines after this to LeetCode
int main() {
    Solution s;
    auto ans = s.capitalizeTitle();
    std::cout << ans << std::endl;
}
'''

# only lines between separator need to be copied back to LeetCode for submit
separator = "//#####"

with open(filepath, 'w') as f:
    # url on LeetCode
    f.write("// %s\n" % params["url"])

    # includes
    for include in includes:
        f.write("#include <%s>\n" % include)

    f.write("using namespace std;\n")
    f.write(separator + "\n")

    # base code from LeetCode
    f.write(re.sub(r"\xa0", " ", params["code"]))  # replace &nbsp; to ' '

    # driver
    f.write("\n")
    f.write(separator + "\n")
    f.write(driver)

print("written to file %s" % filepath.name)
