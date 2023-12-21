// https://leetcode.com/problems/minimum-absolute-difference/
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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        ios_base::sync_with_stdio(false);

//        map<int, vector<vector<int>>> diffs;
//        // map is sorted, so map->first() points to the element with min key
//        diffs[INT32_MAX] = {};
//
//        // when sorted, pairs with min difference must be next to each other, otherwise the diff would be bigger
//        sort(arr.begin(), arr.end());
//
//        for (int i = 1; i < arr.size(); i++) {
//            int diff = arr[i] - arr[i - 1];
//            if (diff <= diffs.begin()->first) {
//                // only store pairs with min diff, discard others
//                diffs[diff].push_back(vector<int>{arr[i - 1], arr[i]});
//            }
//        }
//
//        return diffs.begin()->second;

        map<int, vector<vector<int>>> diffs;
        // map is sorted, so map->first() points to the element with min key
        diffs[INT32_MAX] = {};

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                // for each pair
                int diff = abs(arr[i] - arr[j]);
                if (diff <= diffs.begin()->first) {
                    // only store pairs with min diff, discard others
                    diffs[diff].push_back(vector<int>{min(arr[i], arr[j]), max(arr[i], arr[j])});
                }
            }
        }

        return diffs.begin()->second;
    }
};

//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<vector<int>> ans;
    vector<int> arr;

    arr = {4, 2, 1, 3}; // Output: [[1,2],[2,3],[3,4]]
//    arr = {1, 3, 6, 10, 15}; // Output: [[1,3]]
//    arr = {3, 8, -10, 23, 19, -4, -14, 27};//  Output: [[-14,-10],[19,23],[23,27]]
    ans = sol.minimumAbsDifference(arr);
    print2D(ans);
}
        