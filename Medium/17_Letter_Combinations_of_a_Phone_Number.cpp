// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
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
#include "../lib/ListNode.h"
#include "../lib/TreeNode.h"
#include "../lib/utils.h"
using namespace std;
//#####
class Solution {
private:
    unordered_map<char, string> letters {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
public:
    vector<string> letterCombinations(string digits) {
        ios_base::sync_with_stdio(false);
        vector<string> ans;
        string one;
        p(digits, 0, ans, one);
        return ans;
    }

    void p(const string &digits, int n, vector<string> &ans, string &one) {
        for(const char ch: letters[digits[n]]) {
            one += ch;
            if (n == digits.length()-1) { // last one
                ans.push_back(one);
            } else {
                p(digits, n+1, ans, one);
            }
            one.pop_back();
        }
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<string> ans;
    string digits;

    digits = "23";
    ans = sol.letterCombinations(digits);
    print1D(ans);
}
        