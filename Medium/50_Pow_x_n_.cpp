// https://leetcode.com/problems/powx-n/description/
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
using namespace std;
//#####
class Solution {
    unordered_map<int, double> cache;
public:
    double myPow(double x, int n) {
        // there are far better algorithm for exponentiation
        // https://en.wikipedia.org/wiki/Exponentiation_by_squaring#Recursive_version
        // the idea is: n^5 = n^1 * n^4, 1 and 4 correspond to 1s in binary 1001(5)
        ios_base::sync_with_stdio(false);

        if (x == 0) return 0;
        if (n == 0 || x == 1) return 1;
        if (x == -1) {
            if (n % 2 == 0) {
                return 1;
            } else {
                return -1;
            }
        };

        double ans = 1;
        int k = 1;
        int m;
        if (n == INT32_MIN) {
            m = abs(n+1);
        } else {
            m = abs(n);
        }
        int count = 0;
        while (m != 0 && count < 32) {
            if ((m & 1) == 1) {
                ans *= powOfTwo(x, k);
            }
            m = m >> 1;
            k = k << 1;
            count++;
        }

        if (n == INT32_MIN) {
            return x / ans;
        }

        return n > 0 ? ans : 1 / ans;
    }

    double powOfTwo(double x, int k) {
        // k is power of 2, e.g. 1 2 4 8 16...
        if (k == 1) {
            return x;
        }
        if (k == -1) {
            return 1/x;
        }

        if (!cache.contains(k)) {
            if (k > 0) {
                cache[k] = powOfTwo(x, k / 2) * powOfTwo(x, k / 2);
            } else {
                cache[k] = 1/powOfTwo(x, k / 2) * 1/powOfTwo(x, k / 2);
            }
        }
        return cache[k];
    }
};


//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    double ans
        int k = 1;
        int m;
        if (n == INT32_MIN) {
            m = abs(n+1);
        } else {
            m = abs(n);
        }
        int count = 0;
    double x;
int n;

    x=;
n;
    ans = sol.myPow(x, n);
    std::cout << ans << std::endl;
}
        