// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

//#####
class Solution {
public:
    string toHex(int num) {
        // this is a better solution: https://leetcode.com/problems/convert-a-number-to-hexadecimal/solutions/89238/concise-c-solution/
        // improvement:
        // 1. use look up table, instead of arithmitic, more consicse, given small char set
        // 2. use count++ < 8 for loop control, so no need to convert to unsigned
        if (num == 0) return "0";

        // extract bits in groups of 4
        stack<char> builder;

        unsigned int newNum = (unsigned int) num;
        while (newNum != 0) {
            int temp = newNum & 0xF; // 1111
            if (temp < 10) {
                builder.push('0' + temp);
            } else {
                builder.push('a' + (temp - 10));
            }

            newNum = newNum >> 4;
        }

        string ans;
        while (!builder.empty()) {
            ans += builder.top();
            builder.pop();
        }

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    string ans;
    int num;

    num = 26;;
    num = -1;
    num = 0;
    ans = sol.toHex(num);
    std::cout << ans << std::endl;
}
        