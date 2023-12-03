// https://leetcode.com/problems/rearrange-spaces-between-words/
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
    string reorderSpaces(string text) {
        int counterSpace = 0, counterWord = 0;

        bool wordStart = false;
        for (const char ch: text) {
            if (ch == ' ') {
                counterSpace++;
                if (wordStart) {
                    wordStart = false;
                    counterWord++;
                }
                continue;
            }

            wordStart = true;
        }
        // deal with left one
        if (wordStart) counterWord++;

        if (counterSpace == 0) return text;
        int gap, tail;
        if (counterWord == 1) {
            gap = 0;
            tail = counterSpace;
        } else {
            gap = counterSpace / (counterWord - 1);
            tail = counterSpace % (counterWord - 1);
        }
        string s;
        wordStart = false;
        for (const char ch: text) {
            if (ch == ' ') {
                if (wordStart && (counterWord - 1) > 0) { // only print gap when has gap left
                    wordStart = false;
                    // copy gap
                    for (int i = 0; i < gap; i++) {
                        s += ' ';
                    }
                    counterWord--;
                }
                continue;
            }

            // copy word
            wordStart = true;
            s += ch;
        }
        for (int i = 0; i < tail; i++) {
            s += ' ';
        }
        return s;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    string ans;
    string text;

//    text = "  this   is  a sentence ";
    text = " practice   makes   perfect";
    text = "  hello";
    ans = sol.reorderSpaces(text);
    std::cout << ans << '"' << std::endl;
}
        