// https://leetcode.com/problems/decode-ways/
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
    const set<string> keys {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
    int ans = 0;
    map<int, int> cache;

public:
    int numDecodings(string s) {
        ios_base::sync_with_stdio(false);

        recursion(s, 0);

        return ans;
    }

    void recursion(const string &s, int pos) {
        if (s[pos] == '0') {
            return; // invalid
        }

        // base case
        if (pos >= (s.length() - 1)) {
            ans++;
            return;
        }

        if (cache.contains(pos)) {
            ans += cache[pos];
            return;
        }

        recursion(s, pos+1);
        cache[pos+1] = ans;

        if (keys.find(s.substr(pos, 2)) != keys.end()) {
            recursion(s, pos+2);
            cache[pos+2] = ans;
        }
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    string s;

    s = "111111111111111111111111111111111111111111111"; // 1836311903
    s = "226"; // 3
    s = "06"; // 0
    s = "12"; // 2
    ans = sol.numDecodings(s);
    std::cout << ans << std::endl;
}
        