// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
//#####
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>> &indices) {
        // incrementing a row once toggles all entries of the row from even to odd or odd to even
        // incrementing a row twice doesn't change the entries
        // the same for column
        vector<bool> rowFlags(m, false); // false means even
        vector<bool> colFlags(n, false);

        // record rows and columns which are actually changed after all increment
        for (const auto index: indices) {
            rowFlags[index[0]].flip();
            colFlags[index[1]].flip();
        }

        // count the number of changed rows and cols
        int countRow = 0, countCol = 0;
        for (const auto f: rowFlags) {
            countRow += f;
        }
        for (const auto f: colFlags) {
            countCol += f;
        }

        // odd cells are those only changed in row or col not both
        return countRow * n + countCol * m - countRow * countCol * 2;
    }
};
//#####

//===== do not copy lines after this to LeetCode
int main() {
    Solution sol;
    int ans;
    int m;
    int n;
    vector<vector<int>> indices;

    m = 2;
    n = 3;
    indices = {{0, 1},
               {1, 1}};
    ans = sol.oddCells(m, n, indices);
    std::cout << ans << std::endl;

    m = 2;
    n = 2;
    indices = {{1, 1},
               {0, 0}};
    ans = sol.oddCells(m, n, indices);
    std::cout << ans << std::endl;

    m = 48;
    n = 37;
    indices = {{40, 5}};
    ans = sol.oddCells(m, n, indices);
    std::cout << ans << std::endl;
}
