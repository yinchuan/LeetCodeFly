// https://leetcode.com/problems/remove-duplicate-letters/?envType=daily-question&envId=2023-11-30
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
    string removeDuplicateLetters(string s) {
        // idea: branch, then pick the smallest
        set<string> temp, temp2;
        temp.insert(string{s[0]});
        for(int i = 1; i < s.length(); i++) {
            temp2 = temp;
            temp.clear();
            for(const auto &entry: temp2) {
                auto loc = entry.find(s[i]);
                if (loc == -1) { // never seen, append
                    temp.insert(entry + s[i]);
                } else { // branching
                    temp.insert(entry);
                    temp.insert(entry.substr(0, loc) + entry.substr(loc+1, entry.length()-loc) + s[i]); // before ch + after ch + ch
                }
            }
        }
        return *min_element(temp.begin(), temp.end());
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    string ans;
    string s;

//    s = "bcabc"; // abc
//    s = "cbacdcbc"; // acdb
    s = "abacb"; // abc
    s = "rusrbofeggbbkyuyjsrzornpdguwzizqszpbicdquakqws";
    ans = sol.removeDuplicateLetters(s);
    std::cout << ans << std::endl;
}
        