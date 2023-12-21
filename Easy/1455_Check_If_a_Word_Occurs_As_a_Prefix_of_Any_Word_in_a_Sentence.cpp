// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/
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
    int isPrefixOfWord(string sentence, string searchWord) {
        // 1. passed, by logic is a messy
        // int wordIndex = 1;
        // bool inWord = false;
        // bool start = true;
        // for(int i = 0, j = 0; i < sentence.length(); i++) {
        //     if (sentence[i] == ' ') {
        //         if (inWord) {
        //             wordIndex++;
        //             inWord = false;
        //         }
        //         j = 0; // reset j pointer
        //         start = true;
        //         continue;
        //     }

        //     if (!start) continue;
        //     inWord = true;
        //     if (sentence[i] == searchWord[j]) {
        //         j++;
        //         if (j == searchWord.length()) {
        //             return wordIndex;
        //         }
        //     } else {
        //         j = 0;
        //         start = false;
        //     }
        // }

        // 2 use state machine
        enum states {
            INIT, PREFIX, CONTINUE, END
        };
        enum inputs {
            SPACE, LETTER
        };
        unordered_map<enum states, unordered_map<enum inputs, enum states>> jump;

        jump[INIT] = unordered_map<enum inputs, enum states>{
                {SPACE,  INIT},
                {LETTER, PREFIX}
        };
        // if equal, PREFIX -> PREFIX, if all equal, return
        jump[PREFIX] = unordered_map<enum inputs, enum states>{
                {SPACE,  END},
                {LETTER, PREFIX} // jump to CONTINUE when not equal
        };
        jump[CONTINUE] = unordered_map<enum inputs, enum states>{
                {LETTER, CONTINUE},
                {SPACE,  END}
        };
        // increase wordIndex
        jump[END] = unordered_map<enum inputs, enum states>{
                {SPACE,  END},
                {LETTER, PREFIX}
        };

        int wordIndex = 1;
        enum states state = INIT;
        int j = 0;
        for (const char ch: sentence) {
            auto input = ch == ' ' ? SPACE : LETTER;
            state = jump[state][input];

            if (state == PREFIX) {
                if (ch == searchWord[j]) {
                    j++;
                    if (j == searchWord.length()) return wordIndex;
                } else {
                    j = 0;
                    state = CONTINUE;
                }
                continue;
            }

            if (state == END) {
                j = 0;
                wordIndex++;
            }
        }


        return -1;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    string sentence;
    string searchWord;

    sentence = "i love eating burger", searchWord = "burg";
    sentence = "b bu bur burg burger";
    searchWord = "burg";
    ans = sol.isPrefixOfWord(sentence, searchWord);
    std::cout << ans << std::endl;
}
        