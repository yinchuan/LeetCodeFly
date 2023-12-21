// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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

using namespace std;
//#####
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "";
        }
        // BFS
        string s;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            // layer by layer
            int size = q.size();
            for(int i = 0; i < size; i++) {
                // for last element in a layer
            }
        }

    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//#####

// do not copy lines after this to LeetCode
int main() {
    Codec ser, deser;
    string tree = "[1,2,3,null,null,4,5]";
    TreeNode *root = ser.deserialize(tree);
    TreeNode *ans = deser.deserialize(ser.serialize(root));

}
        