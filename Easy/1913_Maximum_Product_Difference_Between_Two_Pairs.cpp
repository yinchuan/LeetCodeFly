// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/?envType=daily-question&envId=2023-12-18
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
    int maxProductDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int large = INT32_MIN, secondLarge = INT32_MIN;
        int secondSmall = INT32_MAX, small = INT32_MAX;

        for(const int num: nums) {
            if (num > large) {
                secondLarge = large;
                large = num;
            } else if (num > secondLarge) {
                secondLarge = num;
            }

            if (num < small) {
                secondSmall = small;
                small = num;
            } else if (num < secondSmall) {
                secondSmall = num;
            }
        }

        return large * secondLarge - small * secondSmall;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    vector<int> nums;

    nums = {1,6,7,5,2,4,10,6,4};
    ans = sol.maxProductDifference(nums);
    std::cout << ans << std::endl;
}
        