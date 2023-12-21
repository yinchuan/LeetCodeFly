// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/?envType=daily-question&envId=2023-12-14
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
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);

        int m = grid.size();
        int n = grid[0].size();

        vector<int> oneInRows(m);
        vector<int> oneInCols(n);

        // couting 1s in rows and cols
        for(int row = 0; row < m; row++) {
            for (int col = 0; col < n; col ++) {
                oneInRows[row] += grid[row][col];
                oneInCols[col] += grid[row][col];
            }
        }

        // follow the formula
        vector<vector<int>> ans(m, vector<int>(n));
        int deduction = m + n;
        for(int row = 0; row < m; row++) {
            for (int col = 0; col < n; col ++) {
                ans[row][col] = 2 * (oneInRows[row] + oneInCols[col]) - deduction;
            }
        }
        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<vector<int>> ans;
    vector<vector<int>> grid;

    grid = {{0,1,1},{1,0,1},{0,0,1}}; // Output: [[0,0,4],[0,0,4],[-2,-2,2]]
    ans = sol.onesMinusZeros(grid);
    print2D(ans);
}
        