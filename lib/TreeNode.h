//
// Created by yinchuan on 9/12/23.
//

#ifndef LEETCODEFLY_TREENODE_H
#define LEETCODEFLY_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //LEETCODEFLY_TREENODE_H
