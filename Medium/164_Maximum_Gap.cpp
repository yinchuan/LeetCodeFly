// https://leetcode.com/problems/maximum-gap/
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
    int maximumGap(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        if (nums.size() < 2) return 0;

        // max gap at average gap
        // spread nums to buckets which have size smaller than average gap, then it's safe to ignore gaps within a bucket
        // the max gap must be max - prev min

        int n = nums.size();
        int maxV = *max_element(nums.begin(), nums.end());
        int minV = *min_element(nums.begin(), nums.end());
        int avgGap = ceil((maxV - minV) / (double)(n-1));
        if (avgGap == 0) { // all the same
            return 0;
        }

        vector<int> minOfBuckets(n, INT32_MAX);
        vector<int> maxOfBuckets(n, INT32_MIN);
        for (int i = 0; i < n; i++) {
            int index = (nums[i] - minV) / avgGap;
            minOfBuckets[index] = min(minOfBuckets[index], nums[i]);
            maxOfBuckets[index] = max(maxOfBuckets[index], nums[i]);
        }

        int maxGap = INT32_MIN;
        int prev = maxOfBuckets[0];
        for (int i = 1; i < n; i++) {
            if (minOfBuckets[i] == INT32_MAX || maxOfBuckets[i] == INT32_MIN) { // empty bucket
                continue;
            }
            maxGap = max(maxGap, minOfBuckets[i] - prev);
            prev = maxOfBuckets[i];
        }

        return maxGap;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    vector<int> nums;

    nums = {3, 6, 9, 1};
//    nums = {10};
//    nums = {1, 1, 1, 1};
    ans = sol.maximumGap(nums);
    std::cout << ans << std::endl;
}
        