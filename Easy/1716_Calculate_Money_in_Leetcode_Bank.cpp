// https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2023-12-06
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
    int totalMoney(int n) {
        int ans = 0;
        int wholeWeeks = n / 7;
        int left = n % 7;

        // for whole weeks, the first week has 28, each extra week add 7
        // so the last whole week is 28+(n-1)*7
        ans += (28 + 28+(wholeWeeks-1)*7) * wholeWeeks / 2;

        // for left days, Monday is wholeWeeks+1, last day is (wholeWeeks+1) + (left-1)
        ans += left*((wholeWeeks+1) + (wholeWeeks+1 + left-1))/ 2;

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int n;

    n;
    ans = sol.totalMoney(n);
    std::cout << ans << std::endl;
}
        