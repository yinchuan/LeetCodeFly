// https://leetcode.com/problems/minimum-path-sum/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
//#####
// learned from https://leetcode.com/problems/minimum-path-sum/solutions/4332367/beats-94-for-tc-by-being-very-simple-with-6-lines-of-clean-code/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // process first row
        for(int col = 1; col < n; col++) {
            grid[0][col] += grid[0][col-1];
        }

        // process first col
        for(int row = 1; row < m; row++) {
            grid[row][0] += grid[row-1][0];
        };

        // process the rest
        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                grid[row][col] += min(grid[row-1][col], grid[row][col-1]); // accumulate smaller cost from top or left
            }
        }

        return grid.back().back(); // bottom-right cell
    }
};


//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    vector<vector<int>> grid;

    grid;
    ans = sol.minPathSum(grid);
    std::cout << ans << std::endl;
}
        