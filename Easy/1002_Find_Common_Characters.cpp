// https://leetcode.com/problems/find-common-characters/description/
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
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> common, one;
        for(const char ch: words[0]) {
            common[ch]++;
        }

        for(int i=1; i < words.size(); i++) {
            one.clear();
            for(const char ch: words[i]) {
                one[ch]++;
            }

            for(const auto &entry: common) {
                if (one.find(entry.first) == common.end()) {
                    common.erase(entry.first;
                } else {
                    common[entry.first] = min(entry.second, one[entry.first]);
                }
            }
        }

        vector<string> ans;
        for(const auto &entry: common) {
            if (entry.second == 0) continue;

            for(int i = 0; i < entry.second; i++) {
                ans.push_back(string{entry.first});
            }
        }

        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<string> ans;
    vector<string> words;

    words;
    ans = sol.commonChars(words);
    std::cout << ans << std::endl;
}
        