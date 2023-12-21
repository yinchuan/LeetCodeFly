// https://leetcode.com/problems/destination-city/?envType=daily-question&envId=2023-12-15
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
    string destCity(vector<vector<string>> &paths) {
        ios_base::sync_with_stdio(false);

        // 1.
//        unordered_map<string, string> trips;
//
//        for(const auto path: paths) {
//            trips[path[0]] = path[1];
//        }
//
//        auto dst  = trips.begin()->second;
//        while(trips.contains(dst)) {
//            dst = trips[dst];
//        }
//
//        return dst;

        // 2.
//        set<string> sources;

//        for (const auto path: paths) {
//            sources.insert(path[0]);
//        }
//        for (const auto path: paths) {
//            if (sources.find(path[1]) == sources.end()) {
//                return path[1];
//            }
//        }
//        return "";

        // 3.
        unordered_map<string, bool> sources;
        unordered_map<string, bool> candidates;

        for(const auto path: paths) {
            sources[path[0]] = true; // add source
            candidates[path[0]] = false;
            if (!sources.contains(path[1])) {
                candidates[path[1]] = true;
            }
        }

        for(const auto &entry: candidates) {
            if (entry.second) {
                return entry.first;
            }
        }

        return "";
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    string ans;
    vector<vector<string>> paths;

    paths = {{"London",   "New York"},
             {"New York", "Lima"},
             {"Lima",     "Sao Paulo"}};
    ans = sol.destCity(paths);
    std::cout << ans << std::endl;
}
        