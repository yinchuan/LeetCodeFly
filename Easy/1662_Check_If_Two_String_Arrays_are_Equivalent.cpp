// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/?envType=daily-question&envId=2023-12-01
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
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, j1 = 0;
        int i2 = 0, j2 = 0;

        while(true) {
            // both ends, equal
            if (i1 == word1.size() && i2 == word2.size()) {
                return true;
            }
            // one is shorter than the other, not euqal
            if (i1 == word1.size() && i2 != word2.size()) {
                return false;
            }
            if (i1 != word1.size() && i2 == word2.size()) {
                return false;
            }

            // compare pointer
            if (word1[i1][j1] != word2[i2][j2]) {
                return false;
            }

            // update pointers
            if (j1 == word1[i1].length()-1) {
                i1++; j1 = 0;
            } else {
                j1++;
            }
            if (j2 == word2[i2].length()-1) {
                i2++; j2 = 0;
            } else {
                j2++;
            }
        }

        return true;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    bool ans;
    vector<string> word1;
    vector<string> word2;

    word1 = {"ab", "c"}; word2 = {"a", "bc"};
    ans = sol.arrayStringsAreEqual(word1, word2);
    std::cout << ans << std::endl;
}
        