// https://leetcode.com/problems/validate-binary-search-tree/description/
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
private:
    bool inorder(TreeNode *root, TreeNode *&currentMax) {
        if (root->left != nullptr && !inorder(root->left, currentMax)) {
            return false;
        }
        if (currentMax != nullptr && root->val <= currentMax->val) {
            return false;
        }
        currentMax = root;
        if (root->right != nullptr && !inorder(root->right, currentMax)) {
            return false;
        }

        return true;
    }

    bool iterInorder(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *currentMax = nullptr;
        auto node = root;
        while (!s.empty() || node != nullptr) {
            if (node != nullptr) {
                s.push(node);
                node = node->left;
                continue;
            }

            node = s.top();
            s.pop();
            if (currentMax != nullptr && node->val <= currentMax->val) {
                return false;
            }
            currentMax = node;
            node = node->right;
        }

        return true;
    }

public:
    bool isValidBST(TreeNode *root) {
        ios_base::sync_with_stdio(false);

        // store pointer of global max
        // ususally use set initial value of currentMax to be INT32_MIN
        // but a node could have a value of INT32_MIN, it's better to store the global max node
        // learned from fast sample code


        // recursive inorder
        TreeNode *currentMax = nullptr;
        return inorder(root, currentMax);

        // return iterInorder(root);

    }
};

//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    bool ans;
    TreeNode *root;
    TreeNode *&currentMax;

    *root =;
    &currentMax;
    ans = sol.inorder(*root, &currentMax);
    std::cout << ans << std::endl;
}
        