// https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    // idea: iterative in-order, push all left first, learned from fast sample code
    BSTIterator(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        pushAllLeft(root);
    }

    void pushAllLeft(TreeNode* root) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto top = s.top();
        s.pop();

        int ret = top->val;
        pushAllLeft(top->right);

        return ret;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//#####

// do not copy lines after this to LeetCode
int main() {
    Solution sol;
    void ans;
    TreeNode* root;

    root;
    ans = sol.pushAllLeft(root);
    std::cout << ans << std::endl;
}
        