// https://leetcode.com/problems/image-smoother/?envType=daily-question&envId=2023-12-19
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
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        ios_base::sync_with_stdio(false);

        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                int sum = 0;
                int count = 0;

                for(int i=max(0, row-1); i <= min(m-1, row+1); i++) {
                    for(int j = max(0, col-1); j <= min(n-1, col+1); j++) {
                        count++;
                        sum += img[i][j];
                    }
                }
                ans[row][col] = sum / count;
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
    vector<vector<int>> img;

    img = {{100, 200, 100},
           {200, 50,  200},
           {100, 200, 100}}; // Output: [[137,141,137],[141,138,141],[137,141,137]]
    ans = sol.imageSmoother(img);
    print2D(ans);
}
        