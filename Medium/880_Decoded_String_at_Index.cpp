// https://leetcode.com/problems/decoded-string-at-index/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <numeric>
#include <stack>
#include <unordered_map>

using namespace std;
//#####

struct Repeat {
    int pos;
    int len;
    long preLen;

    Repeat(int pos, int len, long preLen) : pos(pos), len(len), preLen(preLen) {}
};

class Solution {
private:
    bool isLetter(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    bool isDigit(char ch) {
        return ch >= '2' && ch <= '9';
    }

public:
    string decodeAtIndex(string s, int k) {
        long tapeLen = 0, prevLen = 0, repeatLen = 0;
        int pos, len = 0; // for a substring
        stack<Repeat> subStrings;
        for (int i = 0; i < s.length();) {
            prevLen = tapeLen;
            len = 0;
            // scan for a string, -> pos, lenOfARun, repeatLen
            pos = i;
            while (isLetter(s[i]) && i < s.length()) {
                len++;
                i++;
            }
            repeatLen = prevLen + len;
            if (k <= repeatLen) {
                // the result is in current substring
                return string{s[pos + k - prevLen - 1]};
            }

            // process digits one by one
            tapeLen = repeatLen;
            while (isDigit(s[i]) && i < s.length()) {
                tapeLen *= (s[i] - '0');
                if (k > tapeLen) {
                    i++;
                    continue;
                }

                k %= repeatLen; // prev + lenOfARun
                if (k == 0) { // end of current string
                    return string{s[pos + len - 1]};
                }
                if (k > prevLen) { // must be in current substring
                    return string{s[pos + k - prevLen - 1]};
                }

                // search stack
                while (!subStrings.empty()) {
                    auto top = subStrings.top();
                    subStrings.pop();
                    k %= (top.preLen + top.len);
                    if (k==0) {
                        return string{s[top.pos+top.len-1]};
                    }
                    if (k > top.preLen) {
                        return string{s[top.pos + k - top.preLen - 1]};
                    }
                }
            }

            // k is beyond current tape, save current substring
            subStrings.push(Repeat(pos, len, prevLen));
        }

        return string{'a'};
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    string ans;
    string s;
    int k;

    s = "a2345678999999999999999"; k = 1; // a
    s = "ha22", k = 5; // h
    s = "leet2code3", k = 10; // 0
    s = "a2b3c4d5e6f7g8h9"; k = 9; // b
    s = "vk6u5xhq9v"; k = 554; ; // k
    s = "vzpp636m8y"; k = 2920; // z
    s = "l3mtm5weq7ki78c7hck4"; k = 165511; // q
    ans = sol.decodeAtIndex(s, k);
    std::cout << ans << std::endl;
}
        