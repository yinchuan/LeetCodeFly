// https://leetcode.com/problems/validate-binary-search-tree/
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);

        int maxLeft=INT32_MIN, minRight = INT32_MAX;

        return recursion(root, maxLeft, minRight);
    }

    bool recursion(TreeNode* root, int &maxLeft, int &minRight) {
        if (root == nullptr) return true;

        if (root->left == nullptr && root->right == nullptr) {
            maxLeft = max(maxLeft, root->val);
            minRight = min(minRight, root->val);
            return true;
        }
        if (root->left != nullptr && root->val <= root->left->val) return false;
        if (root->right != nullptr && root->val >= root->right->val) return false;

        if (root->left != nullptr) {
            int l = INT32_MIN;
            int r = INT32_MAX;
            if (!recursion(root->left, l, r) || root->val <= l) {
                return false;
            }
            maxLeft = max(l, maxLeft);
            minRight = min(r, minRight);
        }

        if (root->right != nullptr) {
            int l2 = INT32_MIN;
            int r2 = INT32_MAX;
            if (!recursion(root->right, l2, r2) || root->val >= r2) {
                return false;
            }
            maxLeft = max(l2, maxLeft);
            minRight = min(r2, minRight);
        }

        return true;
    }

};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    bool ans;
    TreeNode* root;

    root;
    ans = sol.isValidBST(root);
    std::cout << ans << std::endl;
}
        