// https://leetcode.com/problems/permutation-in-string/
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
    bool checkInclusion(string s1, string s2) const {
        if (s2.length() < s1.length()) return false;

        // sliding window, s1.freq must equal window.freq
        unordered_map<char, int> freq1, freqW;

        // freq of s1
        for (const char ch: s1) {
            freq1[ch]++;
        }

        // init window
        int i = 0;
        int window = s1.length();
        for (; i < window; i++) {
            freqW[s2[i]]++;
        }
        if (compareHash(freq1, freqW)) return true;

        char fall = s2[0];
        char add;
        for (; i < s2.length(); i++) {
            fall = s2[i-window];
            add = s2[i];
            if (fall != add) {
                freqW[fall]--;
                freqW[add]++;

                // don't need to compare everything
                if (!freq1.contains(s2[i])) continue;
                if (freq1[fall] != freqW[fall] || freq1[s2[i]] != freqW[s2[i]]) continue;
                if (compareHash(freq1, freqW)) return true;
            }
        }

        return false;
    }

    // hash2 has no less elements, value is the same in both hash for keys in hash1
    bool compareHash(const unordered_map<char, int> &hash1, const unordered_map<char, int> &hash2) const {
        if (hash1.size() > hash2.size()) return false;
        for (const auto &entry: hash1) {
            if (!hash2.contains(entry.first)) return false;
            if (hash2.at(entry.first) != entry.second) return false;
        }

        return true;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    bool ans;
    string s1;
    string s2;

    s1 = "ab", s2 = "eidbaooo"; // 1
//    s1 = "ab", s2 = "eidboaoo"; // 0
    s1 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef";
    s2 = "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg";
    ans = sol.checkInclusion(s1, s2);
    std::cout << ans << std::endl;
}
        