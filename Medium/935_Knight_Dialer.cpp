// https://leetcode.com/problems/knight-dialer/?envType=daily-question&envId=2023-11-27
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
//#####
class Solution {
private:
    int **cache;
    map<int, vector<int>> children{
            {0, vector<int>{4, 6}},
            {1, vector<int>{6, 8}},
            {2, vector<int>{7, 9}},
            {3, vector<int>{4, 8}},
            {4, vector<int>{0, 3, 9}},
            {5, vector<int>{}},
            {6, vector<int>{0, 1, 7}},
            {7, vector<int>{2, 6}},
            {8, vector<int>{1, 3}},
            {9, vector<int>{2, 4}}
    };
public:
    int knightDialer(int n) {
        cache = new int *[n + 1];
        for (int i = 0; i <= n; i++) {
            cache[i] = new int[10]{0};
        }

        int ans = 0;
        for (int i = 0; i <= 9; i++) {
            ans = (ans + countLeaves(i, n)) % (1000000000 + 7);
        }
        return ans;
    }

    int countLeaves(int digit, int len) {
        if (len == 1) {
            return 1;
        }
        // if (digit == 5) return 0;

        int ret = 0, temp;
        for (const int child: children[digit]) {
            if (cache[len][child] == 0) {
                temp = countLeaves(child, len - 1);
                cache[len][child] = temp;
            }
            ret = (ret + cache[len][child]) % 1000000007;
        }
        return ret % (1000000000 + 7);
    }
};

//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int n;

    n = 3131; // 136006598
    ans = sol.knightDialer(n);
    std::cout << ans << std::endl;
}
        