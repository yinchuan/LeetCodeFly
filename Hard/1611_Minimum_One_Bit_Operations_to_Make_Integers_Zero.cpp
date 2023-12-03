// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/?envType=daily-question&envId=2023-11-30
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <numeric>

using namespace std;

//#####
class Solution {
private:
    int n;
    map<int, int> cache;

    int highest(int n) { // assume n != 0
        int ret = -1;
        while (n) {
            n = n >> 1;
            ret++;
        }
        return ret;
    }

    int set(int n, int i, int v) {
        int bit = getBit(n, i);

        if (i == 0) {
            if (bit == v) {
                if (v==1) return 1;
                else return 0;
            } else {
                if (v==1) return 1 + 1;
                else return 1;
            }
        }

        if (bit == v) {
            if (v == 1) return set(n, i-1, 0) + f(i);
            else return set(n, i-1, 0);
        } else {
            if (v == 1) return 1+set(n, i-1, 1) + f(i);
            else return 1 + set(n, i-1, 1);
        }
    }

    int f(int i) {
        if (i < 0) return 0;
        if (!cache.contains(i)) {
            if (i == 0) {
                cache[0] = 1;
            } else {
                cache[i] = 2 * f(i - 1) + 1;
            }
        }

        return cache[i];
    }


    int getBit(int n, int i) {
        return (n >> i) & 1;
    }

public:
    int minimumOneBitOperations(int n) {
        if (n <= 1) return n;
        if (n == 3) return 2;

        int ans = 0;
        int high = highest(n);
//        // 10xxx..., 11xxx...,
        ans += set(n, high - 1, 1);
        ans -= f(high-1); // 10110 -> 11000
        ans += 1;
        ans += f(high-1);

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int n;

    n = 3; // 2
    n = 6; // 4
//    n = 9; // 14
//    n = 333; //393
    ans = sol.minimumOneBitOperations(n);
    std::cout << ans << std::endl;
}
        