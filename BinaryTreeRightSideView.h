//
// Created by August on 4/22/20.
//

#ifndef LEETCODE_BINARYTREERIGHTSIDEVIEW_H
#define LEETCODE_BINARYTREERIGHTSIDEVIEW_H


/**
 * 199. 二叉树的右视图
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res{};
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode *node, int deep, vector<int> &res) {
        if (deep == res.size()) {
            res.push_back(node->val);
        }
        if (node->right) dfs(node->right, deep + 1, res);
        if (node->left) dfs(node->left, deep + 1, res);
    }
};
#endif //LEETCODE_BINARYTREERIGHTSIDEVIEW_H
