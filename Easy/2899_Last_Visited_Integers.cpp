// https://leetcode.com/problems/last-visited-integers/
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
using namespace std;
//#####
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums;
        vector<int> ans;

        int readPointer = -1;
        for(const string &word: words) {
            if (word != "prev") {
                nums.push_back(atoi(word.c_str()));
                readPointer = nums.size() - 1;
            } else {
                if (readPointer < 0) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(nums[readPointer]);
                    readPointer--;
                }
            }
        }

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<int> ans;
    vector<string> words;

    words;
    ans = sol.lastVisitedIntegers(words);
    std::cout << ans << std::endl;
}
        