// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
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
    int numberOfSteps(int num) {
        if (num == 0) return 0;

        int ans = 0;
        while(num != 1) { // reduce num to 1, last 1 needs only 1 step
            if ((num & 1) == 0) {
                ans += 1; // just right shfit by 1
            } else {
                ans += 2; // subtract 1 then right shfit by 1
            }
            num = num >> 1;
        }

        return ans+1;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int num;

    num = 14; // 6
    ans = sol.numberOfSteps(num);
    std::cout << ans << std::endl;
}
        