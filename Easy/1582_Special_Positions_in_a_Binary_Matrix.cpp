// https://leetcode.com/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2023-12-13
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
    int numSpecial(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);

        int ans = 0;
        int m = mat.size();
        int n = mat[0].size();

        vector<bool> cols(n, true);
        vector<bool> rows(m, true);

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if (mat[row][col] == 0) continue;

                // find 1
                if (!cols[col]) {
                    rows[row] = false;
                    continue;
                }
                if (!rows[row]) {
                    cols[col] = false;
                    continue;
                }

                // check rest of the row
                bool valid = true;
                for(int j = col+1; j < n; j++) {
                    if (mat[row][j] == 1) {
                        valid = false;
                        cols[j] = false;
                        rows[row] = false;
                    }
                }
                if (!valid) continue;
                // check rest of the col
                for(int i = row+1; i < m; i++) {
                    if (mat[i][col] == 1) {
                        valid = false;
                        rows[i] = false;
                        cols[col] = false;
                    }
                }
                if (!valid) break;

                ans++;
            }
        }

        return ans;
    }
};

//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    vector<vector<int>> mat;

    mat = {{0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,0,0}};
    print2D(mat);
    ans = sol.numSpecial(mat);
    std::cout << ans << std::endl;
}
        