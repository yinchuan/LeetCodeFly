// https://leetcode.com/problems/happy-number/description/
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
    bool isHappy(int n) {
        ios_base::sync_with_stdio(false);

        while(n != 4) { // all unhappy number reach 4
            int next = 0;
            while(n != 0) {
                next += pow(n % 10, 2);
                n = n / 10;
            }
            if (next == 1) {
                return true;
            }
            n = next;
        }

        return false;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    bool ans;
    int n;

    for(int i = 1; i < 1000; i++) {
        if (sol.isHappy(i)) {
            cout << i << " ";
        }
    }
//    ans = sol.isHappy(n);
//    std::cout << ans << std::endl;
}
        