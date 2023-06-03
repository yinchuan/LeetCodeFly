// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#####
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto n: nums) {
            if (n < 100 && n >= 10) {
                count++;
                continue;
            }
            if (n <10000 && n >= 1000) {
                count++;
                continue;
            }
            if (n == 100000) {
                count++;
                continue;
            }
        }

        return count;
    }
};
//#####

//===== do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    vector<int> nums;
     
    nums = {12,345,2,6,7896};
    ans = sol.findNumbers(nums);
    std::cout << ans << std::endl;

    nums = {555,901,482,1771};
    ans = sol.findNumbers(nums);
    std::cout << ans << std::endl;

    nums = {100000};
    ans = sol.findNumbers(nums);
    std::cout << ans << std::endl;
}
