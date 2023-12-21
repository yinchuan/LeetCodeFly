// https://leetcode.com/problems/reverse-words-in-a-string/
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
    string reverseWords(string s) {
        ios_base::sync_with_stdio(false);
        // 1 use stack, fast, double memory
        // string word;
        // stack<string> words;
        // for(const char ch: s) {
        //     if (ch == ' ') {
        //         if (word.empty()) continue;
        //         words.push(word);
        //         word = "";
        //     } else {
        //         word += ch;
        //     }
        // }
        // if (!word.empty()) words.push(word);

        // string ans;
        // while(!words.empty()) {
        //     ans += words.top();
        //     words.pop();
        //     ans += " ";
        // }
        // if (ans.back() == ' ') {
        //     ans.resize(ans.length()-1);
        // }
        // return ans;

        // 2 O(1) space, learned from solutions
        // step1: reverse whole string
        reverseSub(s, 0, s.length()-1); 

        // step2: remove extra space
        // from https://leetcode.com/submissions/detail/1119320988/
        int write = 0;
        for(int read = 0; read < s.length(); read++) {
            if (s[read] == ' ') {
                // make sure copy one space
                if (write > 0 && s[write-1] != ' ') {
                    s[write] = ' ';
                    write++;
                }
                continue;
            }

            s[write] = s[read];
            write++;
        }
        if (s.back() == ' ') {
            s.resize(write-1);
        } else {
            s.resize(write);
        }

        // step3: reverse each word
        reverseWordsOneSpace(s);

        return s;
    }

    // from https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/1119336333/
    void reverseWordsOneSpace(string &s) {
        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverseSub(s, start, i-1);
                start = i + 1;
            }
        }
        reverseSub(s, start, s.length()-1);
    }

    void reverseSub(string &s, int start, int end) {
        while(start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    string ans;
    string s;

    s = "a good   example";
    s = "  hello world  ";
    ans = sol.reverseWords(s);
    std::cout << ans << ";;;" << std::endl;
}
        