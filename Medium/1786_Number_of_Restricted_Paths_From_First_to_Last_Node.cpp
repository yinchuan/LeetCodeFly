// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/
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
private:
    int n;
    unordered_map<int, int> toLastCache;
    unordered_map<int, map<int, int>> adj; // node to its neighbours

    int toLast(int z) {
        if (toLastCache.contains(z)) {
            return toLastCache[z];
        }

        if (z == n) {
            return 0;
        }

        int result = INT32_MAX;
        for(const auto &neighbour: adj[z]) {
            result = min(result, neighbour.second + toLast(neighbour.first));
        }
        toLastCache[z] = result;
        return toLastCache[z];
    }


public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        this->n  = n;

        for(const auto &edge: edges) {
            adj[edge[0]][edge[1]] = edge[2];
            adj[edge[1]][edge[0]] = edge[2];
        }

        toLast(1);

        return 0;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int n;
    vector<vector<int>> edges;

    n = 5; edges = {{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};
    ans = sol.countRestrictedPaths(n, edges);
    std::cout << ans << std::endl;
}
        