// https://leetcode.com/problems/k-th-symbol-in-grammar/description/
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
public:
    int kthGrammar(int n, int k) {
        // above =  f(n-1, (k+1)/2)
        // return (above+1)/2

        if (n == 1) {
            return 0;
        }

        // can be simplified as
        // return kthGrammar(n-1, (k+1)/2) == k % 2;
        return (kthGrammar(n-1, (k+1)/2) + k % 2 + 1) % 2;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int n;
int k;

    n=;
k;
    ans = sol.kthGrammar(n, k);
    std::cout << ans << std::endl;
}
        