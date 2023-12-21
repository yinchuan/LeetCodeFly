// https://leetcode.com/problems/sort-colors/
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
    void sortColors(vector<int>& nums) {
        int read = 0;
        int write0 = 0;
        int write2 = nums.size() - 1;
        
        while(read <= write2) {
            if (nums[read] == 0) {
                swap(nums[read], nums[write0]);
                if (read == write0) read++;
                write0++;
            } else if (nums[read] == 2) {
                swap(nums[read], nums[write2]);
                write2--;
            } else {
                read++;
            }
        }   
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<int> nums;

    nums = {2,0,2,1,1,0};
    nums = {1, 1, 1, 1, 1, 0, 0, 2, 2, 2,2, 1, 1, 2, 2, 1, 0, 0 };
    sol.sortColors(nums);
    print1D(nums);
}
        