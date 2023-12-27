// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2023-12-22
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
#include "../lib/utils.h"

using namespace std;

//#####
class Solution {
public:
    int maxScore(string s) {
        ios_base::sync_with_stdio(false);

        int totalOnes = 0;
        int maxScore = INT32_MIN;
        int score = 0;
        for (int i = 0; i < s.length()-1; i++) { // not counting the last one
            if (s[i] == '0') {
                score++;
            } else {
                totalOnes++;
                score--;
            }

            maxScore = max(maxScore, score);
        }

        return maxScore + totalOnes + s.back() - '0';  // add 1 if the last char is '1'
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    string s;

    s = "011101";
//    s = "00111";
//    s = "1111";
    s = "000010";
//    s = "00";
//    s = "10";
    ans = sol.maxScore(s);
    std::cout << ans << std::endl;
}
        