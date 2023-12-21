// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21
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
#include <chrono>
using namespace std;
//#####
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        
        // 1. works, not very fast because of sorting
        auto start_time = chrono::high_resolution_clock::now();
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            // return true if a is ordered before b
            return a[0] < b[0];
        });
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << "sorting: " << duration.count() << "ms" << std::endl;


        int maxDiff = INT32_MIN;

        start_time = chrono::high_resolution_clock::now();
        for(int i = 1; i < points.size(); i++) {
            maxDiff = max(points[i][0] - points[i-1][0], maxDiff);
        }
        end_time = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << "picking: " << duration.count() << "ms" << std::endl;

        return maxDiff;

        // 2. use ordered set for sorintg horizontal coordinates
        // also works, not faster than sorting
        // set<int> xs;
        // for(const auto &point: points) {
        //     xs.insert(point[0]);
        // }

        // int maxDiff = INT32_MIN;
        // for(auto prev=xs.begin(), it=++xs.begin(); it != xs.end(); prev++, it++) {
        //     maxDiff = max(*it - *prev, maxDiff);
        // }
        // return maxDiff == INT32_MIN ? 0 : maxDiff;
  
        // 3. use a map to store horizontal coordinates, still not fast
        // map<int, bool> xs; // follow constraints
        // for(const auto &point: points) {
        //     xs[point[0]] = true;
        // }

        // int maxDiff = INT32_MIN;
        // for(auto prev=xs.begin(), it=++xs.begin(); it != xs.end(); prev++, it++) {
        //     maxDiff = max(it->first - prev->first, maxDiff);
        // }
        // return maxDiff == INT32_MIN ? 0 : maxDiff;

        // 4. sorting, then binary search, not finish
        // sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
        //     // return true if a is ordered before b
        //     return a[0] < b[0];
        // });


    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    vector<vector<int>> points;

    points;
    ans = sol.maxWidthOfVerticalArea(points);
    std::cout << ans << std::endl;
}
        