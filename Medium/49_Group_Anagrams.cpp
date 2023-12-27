// https://leetcode.com/problems/group-anagrams/description/
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

private:
    size_t toNumber(const string &str) {
        // learned from fast sample code
        // count freq
        vector<int> counter(26, 0);
        for(const char ch: str) {
            counter[ch-'a']++;
        }            

        // convert freq to key
        size_t key = 0;
        for(int i = 0; i < 26; i++) {
            key = key * 31 + counter[i];
        }

        return key;
    }

    string combineFreq(const string &str) {
        // count freq
        vector<int> counter(26, 0);
        for(const char ch: str) {
            counter[ch-'a']++;
        }            

        // convert freq to key
        string key = "";
        for(int i = 0; i < 26; i++) {
            if (counter[i] != 0) {
                key += 'a'+i;
                key += to_string(counter[i]);
            }
        }
        return key;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        
        vector<vector<string>> ans;

        // to create a pointer-to-member-function: https://isocpp.org/wiki/faq/pointers-to-members#typedef-for-ptr-to-memfn
//        typedef size_t (Solution::*toKeyFn)(const string &);
//        toKeyFn str2key = &Solution::toNumber;
//        unordered_map<size_t, int> keyToIndex;
        typedef string (Solution::*toKeyFn)(const string &);
        toKeyFn str2key = &Solution::combineFreq;
        unordered_map<string, int> keyToIndex;

        for(const auto &str: strs) {
            // to call a pointer-to-member-function, one of below:
//            auto key = (*this.*str2key)(str);
            auto key = invoke(str2key, this, str);

            // find index, add to result
            if (keyToIndex.contains(key)) {
                ans[keyToIndex[key]].push_back(str);
            } else {
                ans.push_back({str});
                keyToIndex[key] = ans.size()-1;
            }
        }

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<vector<string>> ans;
    vector<string> strs  {"eat","tea","tan","ate","nat","bat"};
    ans = sol.groupAnagrams(strs);
    print2D(ans);
}
        