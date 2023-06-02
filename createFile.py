#!/usr/bin/python3

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

# extract function name, return type, parameter from given code
code = re.sub(r"\xa0", " ", params["code"]).replace("\n", "")
match = re.findall("(\w+) (\w+)\((.*)\)", code)
if not match:
    print("re fails to find function name")
    exit()
returnType = match[0][0]
funcName = match[0][1]
parameters = match[0][2]
parameterNames = [p.strip().split(' ')[1] for p in parameters.split(",")]

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
''' % (returnType,
       parameters.replace('&', '').replace(',', '\n;'),
       "=;\n".join(parameterNames),
       funcName,
       ", ".join(parameterNames)
       )

# only lines between separator need to be copied back to LeetCode for submit
separator = "//#####"

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
