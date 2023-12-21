// https://leetcode.com/problems/valid-parenthesis-string/description/
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
    bool checkValidString(string s) {
        // treat all * as left
        int left = 0, right = 0;
        for (const char ch: s) {
            if (ch == '(') {
                left++;
            } else {
                right++;
            }

        }
        if (left > right) return false;

        left = 0, right = 0;
        for (int i = s.length(); i >= 0; i--) {
            if (s[i] == ')') {
                right++;
            } else {
                left++;
            }

        }
        if (right > left) return false;
        return true;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    bool ans;
    string s;

    s = "(*)";
    s = "()";
    s = "(*))";
    s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    ans = sol.checkValidString(s);
    std::cout << ans << std::endl;
}
        