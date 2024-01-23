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
        pushAllLeft(s, root);

        // key for iterative in-order: always go to right after pop
        TreeNode *pre = s.top(); // init pre as smallest element, eliminate check pre!=nullptr in loop
        s.pop();
        pushAllLeft(s, pre->right); // in case root has no left child
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node->val <= pre->val) {
                return false;
            }
            pre = node;
            pushAllLeft(s, node->right);
        }

        return true;
    }

    void pushAllLeft(stack<TreeNode*> &s, TreeNode *root) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }

public:
    bool isValidBST(TreeNode *root) {
        ios_base::sync_with_stdio(false);

        // store pointer of global max
        // ususally use set initial value of currentMax to be INT32_MIN
        // but a node could have a value of INT32_MIN, it's better to store the global max node
        // learned from fast sample code


        // recursive inorder
//        TreeNode *currentMax = nullptr;
//        return inorder(root, currentMax);

         return iterInorder(root);

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
        