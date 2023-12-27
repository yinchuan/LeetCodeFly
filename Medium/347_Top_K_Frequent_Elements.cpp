// https://leetcode.com/problems/top-k-frequent-elements/description/
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
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        unordered_map<int, int> freq;
        for(const auto num: nums) {
            freq[num]++;
        }

        int n = nums.size();

//        vector<int> ans;
//        map<int, vector<int>> buckets;
//        for(const auto &entry: freq) {
//            buckets[entry.second].push_back(entry.first);
//        }
//        for(auto it=buckets.rbegin(); it != buckets.rend() && ans.size() < k; it++) {
//            for(const auto n: it->second) {
//                ans.push_back(n);
//            }
//        }

        vector<int> ans;
        vector<vector<int>> buckets(n+1);
        for(const auto &entry: freq) {
            buckets[entry.second].push_back(entry.first);
        }
        for(int i = buckets.size()-1; i > 0 && ans.size() < k; i--) {
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<int> ans;
    vector<int> nums;
    int k;

    nums = {1,1,1,2,2,3}; k = 2;
    nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6}; k = 10;
    ans = sol.topKFrequent(nums, k);
    print1D(ans);
}
        