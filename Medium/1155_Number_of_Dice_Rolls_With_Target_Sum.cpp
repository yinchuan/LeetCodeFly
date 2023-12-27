// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/?envType=daily-question&envId=2023-12-26
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
private:
    unordered_map<int, unordered_map<int, int>> cache; // n, target -> ways
    unordered_map<int, int> freq;
    int total; // will be used in counting

public:
    // int numRollsToTarget(int n, int k, int target) {
    //     ios_base::sync_with_stdio(false);

    //     return recursion(n, k , target);
    // }

    // int recursion(int n, int k, int target) {
    //     if (cache.contains(n) && cache[n].contains(target)) {
    //         return cache[n][target];
    //     }
    //     if (target > n*k) {
    //         cache[n][target] = 0;
    //         return 0;
    //     }
    //     if (target == n*k || n == 1) {
    //         cache[n][target] = 1;
    //         return 1;
    //     }

    //     int ans = 0;
    //     int limit = min(k, target - n + 1);
    //     for(int i = max(1, target-(n-1)*k); i <= limit; i++) {
    //         ans = (ans + recursion(n-1, k, target-i)) % 1000000007;
    //     }
    //     cache[n][target] = ans;

    //     return ans;
    // }


    int numRollsToTarget(int n, int k, int target) {
        ios_base::sync_with_stdio(false);
        total = n;
        return recursion(n, k, target, -1);
    }

    int recursion(int n, int k, int target, int pre) {
//        if (cache.contains(n) && cache[n].contains(target)) {
//            return cache[n][target];
//        }
        if (target > n * k) {
            cache[n][target] = 0;
            return 0;
        }
//        if (target == n * k && n != 1) {
//            cache[n][target] = countFreq();
//            return cache[n][target];
//        }

        int start = max(1, max(target - (n - 1) * k, pre));
        int limit = min(k, target - n + 1);
        if (start > limit) {
            cache[n][target] = 0;
            return 0;
        }

        if (n == 1) {
            freq[target]++;
            // counting from freq
            int ans = countFreq();
            // set cache
//            cache[n][target] = ans;

            // undo freq
            freq[target]--;
            return ans;
        }

        int ans = 0;
        // each dice can't be smaller than previous one
        for (int i = start; i <= limit; i++) {
            freq[i]++;
            ans = (ans + recursion(n - 1, k, target - i, i)) % 1000000007;
            freq[i]--;
        }
        cache[n][target] = ans;
        return ans;
    }

    int countFreq() {
        int ans = 1;
        int whole = total;
        for (const auto &entry: freq) {
            if (entry.second == 0) continue;
            cout << entry.first << ": " << entry.second << ", ";
            ans = ans * choose(whole, entry.second) % 1000000007;
            whole -= entry.second;
        }
        cout << endl;
        return ans;
    }

    int choose(int n, int k) {
        if (n == k) return 1;
        int ans = 1;
        for (int higher = n, lower = 1; lower <= k; higher--, lower++) {
            ans = (ans / lower * higher);
        }
        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int n;
    int k;
    int target;

//    for(int i = 1, n = 10; i < 10; i++) {
//        cout << "choose(" << n << ", " << i << "): " << sol.choose(n, i) << endl;
//    }

    n = 1, k = 6, target = 3;
//    n = 2, k = 6, target = 7;
    n = 30, k = 30, target = 500;
    ans = sol.numRollsToTarget(n, k, target);
    std::cout << ans << std::endl;
}
        