// https://leetcode.com/problems/capitalize-the-title/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

//#####
class Solution {
public:
    string capitalizeTitle(string title) {
        int i = 0;
        int len = 0;
        while (i < title.length()) {
            if (title[i] == ' ') {
                // at the end of a word, check if upper the first letter
                if (len > 2) {
                    title[i - len] -= 32; // toUpper
                }
                len = 0;
                i++;
                continue;
            }

            // lower all by default
            if (title[i] <= 'Z') {
                title[i] += 32;
            }
            len++;
            i++;
        }
        // deal with last word
        if (len > 2) {
            title[i - len] -= 32;
        }

        return title;
    }
};
//#####

//===== do not copy lines after this to LeetCode
int main() {
    Solution s;
    auto ans = s.capitalizeTitle("i lOve leetcode");
    std::cout << ans << std::endl;
}
