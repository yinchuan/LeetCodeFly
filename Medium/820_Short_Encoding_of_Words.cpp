// https://leetcode.com/problems/short-encoding-of-words/description/
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
class Trie {
private:
    char key;
    map<char, Trie *> children;
public:
    Trie(char key) : key(key) {}

    void insert(const string &word) {
        auto temp = this;
        for (int i = word.length() - 1; i >= 0; i--) {
            if (!temp->children.contains(word[i])) {
                temp->children[word[i]] = new Trie(word[i]);
            }
            temp = temp->children[word[i]];
        }
    }

    void collect(int &total, int &one) {
        if (key != '\0') one++;

        if (children.empty()) { // leaf node
            total += one + 1; // plug 1 for '#'
            one--;
            return;
        }

        for (const auto &entry: children) {
            entry.second->collect(total, one);
        }
        if (key != '\0') one--;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        int ans = 0;
        // 1. counting, passed, slow
//        sort(words.begin(), words.end(), [](const string &s1, const string s2) {
//            return s1.length() > s2.length();
//        });
//
//        map<string, int> suffixCounter;
//        for (const auto &word: words) {
//            if (suffixCounter.contains(word)) {
//                continue;
//            }
//            // new long word
//            ans += word.length() + 1;
//            for (int pos = word.length() - 1, count = 1; pos >= 0; pos--, count++) {
//                suffixCounter[word.substr(pos, count)]++;
//            }
//        }
//

        auto trie = new Trie('\0');
        for (const auto &word: words) {
            trie->insert(word);
        }

        int one = 0;
        trie->collect(ans, one);
        return ans;
    }
};


//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    vector<string> words = {"time", "me", "bell"};
    words = {"t"};

    ans = sol.minimumLengthEncoding(words);
    std::cout << ans << std::endl;
}
        