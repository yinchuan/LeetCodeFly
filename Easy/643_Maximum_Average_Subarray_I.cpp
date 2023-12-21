// https://leetcode.com/problems/maximum-average-subarray-i/
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
    double findMaxAverage(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);

        int sum = 0, ans;
        int i = 0;
        // init window
        for (; i < k; i++) {
            sum += nums[i];
        }

        ans = sum;
        // sliding
        for (; i < nums.size(); i++) {
            sum = sum + nums[i] - nums[i - k];
            ans = max(ans, sum);
        }

        return ans / (double) k;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    double ans;
    vector<int> nums;
    int k;

    nums = {0, 4, 0, 3, 2};
    k = 1;
    ans = sol.findMaxAverage(nums, k);
    std::cout << ans << std::endl;
}
        