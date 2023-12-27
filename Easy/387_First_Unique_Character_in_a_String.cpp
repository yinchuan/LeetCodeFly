// https://leetcode.com/problems/first-unique-character-in-a-string/description/
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
#include <cmath>
#include "../lib/ListNode.h"
#include "../lib/TreeNode.h"
#include "../lib/utils.h"
using namespace std;
//#####
class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);

        // 1. 
        // record index, if repeat, mark as invalid
        // unordered_map<char, pair<int, bool>> m;

        // for(int i = 0; i < s.length(); i++) {
        //     if (m.contains(s[i])) {
        //         m[s[i]].second = false;
        //     } else {
        //         m[s[i]] = {i, true};
        //     }
        // }

        // int minIndex = INT32_MAX;
        // for(const auto &entry: m) {
        //     if (!entry.second.second) continue;

        //     if (entry.second.first < minIndex) {
        //         minIndex = entry.second.first;
        //     }
        // }

        // return minIndex == INT32_MAX ? -1 : minIndex;


        // 2. 
        vector<int> counter(26, 0);
        for(const char ch: s) {
            counter[ch-'a']++;
        }
        // this implictly gives the first index of non-repeating char
        for(int i = 0; i < s.length(); i++) {
            if (counter[s[i]-'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    string s;

    s;
    ans = sol.firstUniqChar(s);
    std::cout << ans << std::endl;
}
        