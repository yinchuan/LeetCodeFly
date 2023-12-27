// https://leetcode.com/problems/valid-sudoku/description/
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
#include <cmath>
#include "../lib/ListNode.h"
#include "../lib/TreeNode.h"
#include "../lib/utils.h"

using namespace std;

//#####
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        ios_base::sync_with_stdio(false);

        // use three bitmaps for repetition detection
        int rows[9] = {0};
        int cols[9] = {0};
        int subs[9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int digit = board[i][j] - '1';

                if ((rows[i] >> digit) & 1) {
                    cout << "row: " << i << ", " << j << ": " << digit << endl;
                    return false;
                }
                rows[i] |= (1 << digit);

                if ((cols[j] >> digit) & 1) {
                    cout << "row: " << i << ", " << j << ": " << digit << endl;
                    return false;
                }
                cols[j] |= (1 << digit);

                if ((subs[i / 3 * 3 + j / 3] >> digit) & 1) {
                    cout << "row: " << i << ", " << j << ": " << digit << endl;
                    return false;
                }
                subs[i / 3 * 3 + j / 3] |= (1 << digit);
            }
        }

        return true;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    bool ans;
    vector<vector<char>> board;

    board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    ans = sol.isValidSudoku(board);
    std::cout << ans << std::endl;
}
        