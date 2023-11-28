// https://leetcode.com/problems/divide-two-integers/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;

//#####
class Solution {
private:
    // both n and d are unsigned
    // https://en.wikipedia.org/wiki/Division_algorithm#Long_division
    int longDivision(int n, int d) {
        // credit: https://leetcode.com/problems/divide-two-integers/solutions/13418/c-8ms-solution-without-long-long/
        int q = 0, r = 0;
        for (int i = 31; i >= 0; i--) {
            r = r << 1;
            r |= ((n >> i) & 1); // r[0] == n[i]
            if (r >= d) {
                r -= d;
                q |= 1 << i;
            }
        }
        return q;
    }

public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        if (divisor == INT_MIN) return 0;
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            return ~dividend + 1;
        }

        // nominator, denominator, quotient
        int n, d, q;
        if (dividend == INT_MIN) {
            d = abs(divisor);
            // increase dividend to be able to abs();, compensate 1 for quotient later
            // abs(INT_MIN) will overflow
            n = abs(dividend + d);
            q = longDivision(n, d);
            q += 1; // compensation
        } else {
            n = abs(dividend);
            d = abs(divisor);
            q = longDivision(n, d);
        }

        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return q;
        } else {
            return ~q + 1;
        }
    }
};

//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int dividend;
    int divisor;

//    dividend=-2147483648; divisor = -1;
//    dividend = -2147483648; divisor = 2;
//    dividend=-1010369383; divisor = -2147483648;
//    dividend=-2147483648; divisor = -2147483648;
    dividend=-2147483648; divisor = 2147483647;
//    dividend=16; divisor = 4;
    ans = sol.divide(dividend, divisor);
    std::cout << ans << std::endl;
}
        