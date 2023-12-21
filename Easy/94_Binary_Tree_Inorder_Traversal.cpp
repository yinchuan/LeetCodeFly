// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

//        inorder(root, ans);
//        return ans;
//        return inorder_iter(root);
        return inorder_iter_better(root);
    }

    void inorder(TreeNode* root, vector<int> &ans) {
        if (root == nullptr) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorder_iter(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        unordered_map<TreeNode *, bool> visited;
        stack<TreeNode *> s;
        s.push(root);

        while(!s.empty()) {
            auto top = s.top();
            s.pop();

            if (visited[top]){
                ans.push_back(top->val);
                continue;
            }
            visited[top] = true;

            if (top->right != nullptr) s.push(top->right);
            s.push(top);
            if (top->left != nullptr) s.push(top->left);
        }

        return ans;
    }

    vector<int> inorder_iter_better(TreeNode* root) {
        //
        // compare to iorder_iter, remove visited vector

        vector<int> ans;
        stack<TreeNode*> s;
        while(!s.empty() || root != nullptr) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    vector<int> ans;
    TreeNode* root;

    root;
    ans = sol.inorderTraversal(root);
}
        