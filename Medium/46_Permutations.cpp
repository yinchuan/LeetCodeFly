// https://leetcode.com/problems/permutations/
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
    vector<vector<int>> permute(vector<int> &nums) {
        map<int, bool> used;
        for (const int num: nums) {
            used[num] = false;
        }
        vector<vector<int>> ans;
        vector<int> one(nums.size());

        p(nums, 0, ans, one, used);
        return ans;
    }

    void p(vector<int> &nums, int i, vector<vector<int>> &ans, vector<int> &one, map<int, bool> &used) {
        for (const int num: nums) {
            if (used[num]) continue;

            one[i] = num;
            if (i == nums.size() - 1) { // last one
                ans.push_back(one);
                return;
            }

            used[num] = true;
            p(nums, i + 1, ans, one, used);
            used[num] = false;
        }
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<vector<int>> ans;
    vector<int> nums{1, 2, 3, 4};
    ans = sol.permute(nums);
    print2D(ans);
}
        