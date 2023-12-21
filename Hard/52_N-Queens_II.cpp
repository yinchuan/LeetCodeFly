// https://leetcode.com/problems/n-queens-ii/
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
    int size;
    int **grid;

    void queen(int row, int &count) {
        for (int col = 0; col < size; col++) {
            if (isUnderAttack(row, col)) {
                continue;
            }

            if (row == size - 1) { // last row
                count++; // find a solution
                continue; // no need to place and unplace for last row
            }

            updateAttackArea(row, col, 1);
            queen(row + 1, count);
            updateAttackArea(row, col, -1);
        }
    }

    bool isUnderAttack(int row, int col) {
        return grid[row][col] > 0;
    }

    void updateAttackArea(int row, int col, int value) {
        // same row
        for (int j = 0; j < size; j++) {
            grid[row][j] += value;
        }

        // same col
        for (int i = 0; i < size; i++) {
            grid[i][col] += value;
        }

        // diagonal, nw-se
        int i, j;
        diagonalNW(row, col, i, j);
        for (; i < size && j < size; i++, j++) {
            grid[i][j] += value;
        }
        // diagonal, sw-ne
        diagonalSW(row, col, i, j);
        for (; i >= 0 && j < size; i--, j++) {
            grid[i][j] += value;
        }

    }

    static void diagonalNW(int row, int col, int &i, int &j) {
        i = max(0, row - col);
        j = max(0, col - row);
    }

    void diagonalSW(int row, int col, int &i, int &j) const {
        int sum = row + col;
        i = min(sum, size - 1);
        j = max(0, sum - (size - 1));
    }

public:
    int totalNQueens(int n) {
        ios_base::sync_with_stdio(false);
        if (n == 1) return 1;
        if (n == 2) return 0;
        size = n;
        // 2D array to store attack area: increase by 1 for each queue by who can be attacked
        grid = new int *[n];
        for (int i = 0; i < n; i++) {
            grid[i] = new int[n];
            for (int j = 0; j < n; j++) {
                grid[i][j] = 0;
            }
        }

        int ans = 0;
        queen(0, ans);
        for (int i = 0; i < size; i++) {
            delete[] grid[i];
        }
        delete[] grid;
        return ans;
    }

};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    cout << sol.totalNQueens(4) << endl;
    for (int i = 1; i <= 9; i++) {
        cout << i << ": ";
        cout << sol.totalNQueens(i) << endl;
    }
}
        