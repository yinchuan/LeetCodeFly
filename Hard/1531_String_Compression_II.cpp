// https://leetcode.com/problems/string-compression-ii/?envType=daily-question&envId=2023-12-28
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
#include <cmath>
#include "../lib/ListNode.h"
#include "../lib/TreeNode.h"
#include "../lib/utils.h"

using namespace std;

//#####

class Solution {
    struct RunLength {
        char ch;
        int length;

        RunLength(char ch, int length) : ch(ch), length(length) {};
    };

    int globalMin = INT32_MAX;

public:
    int getLengthOfOptimalCompression(string s, int k) {
        ios_base::sync_with_stdio(false);

        auto runs = split(s);
        bool allSingle = true;
        for(const auto run: runs) {
            if (run.length > 1) {
                allSingle = false;
            }
        }
        if (allSingle) {
            return totalLen(runs) - k;
        }

        printRuns(runs);
        recursion(runs, 0, k);
        return globalMin;
    }

    void printRuns(const vector<RunLength> &runs) {
        for (const auto run: runs) {
            cout << run.ch << ": " << run.length << endl;
        }
        cout << "compressed lenOfARun: " << totalLen(runs) << endl;
    }

    void recursion(vector<RunLength> &runs, int current, int k) {
        if (current > runs.size() - 1) return;
        for (int i = 0; i <= runs[current].length && i <= k; i++) {
            runs[current].length -= i;
            globalMin = min(globalMin, totalLen(runs));
            recursion(runs, current + 1, k - i);
            runs[current].length += i;
        }
    }

    int lenOfARun(int count) const {
        if (count == 0) {
            return 0;
        }
        if (count == 1) {
            return 1;
        }
        if (count < 10) {
            return 2;
        }
        if (count < 100) {
            return 3;
        }
        return 4;
    }

    int totalLen(const vector<RunLength> &runs) {
        int ret = 0;
        int len = runs[0].length;
        int pre = 0;
        for (int i = 1; i < runs.size(); i++) {
            if (runs[i].length == 0) continue;

            if (runs[i].ch != runs[pre].ch) {
                ret += lenOfARun(len);
                len = runs[i].length;
                pre = i;
            } else {
                len += runs[i].length;
            }
        }
        ret += lenOfARun(len);
        return ret;
    }

    vector<RunLength> split(const string &s) {
        vector<RunLength> ret;
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                ret.push_back(RunLength(s[i - 1], count));
                count = 1;
            } else {
                count++;
            }
        }
        ret.push_back(RunLength(s.back(), count));
        return ret;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    string s;
    int k;

    s = "aaabcccd", k = 2; // 4
    s = "aabbaa", k = 2; // 2
    s = "aaaaaaaaaaa", k = 0; // 3
    s = "aaaaaaaaaa", k = 1; // 2
    s = "bbabbbabbbbcbb", k = 4; // 3
    s = "abcdefghijklmnopqrstuvwxyz"; k = 16;
    s = "abcdefghijklmnopqrstuvwxyzz"; k = 12;
    ans = sol.getLengthOfOptimalCompression(s, k);
    std::cout << ans << std::endl;
}
        