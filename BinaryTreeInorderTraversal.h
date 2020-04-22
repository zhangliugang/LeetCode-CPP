//
// Created by August on 4/22/20.
//

#ifndef LEETCODE_BINARYTREEINORDERTRAVERSAL_H
#define LEETCODE_BINARYTREEINORDERTRAVERSAL_H

/**
 * 94. 二叉树的中序遍历
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 非递归
 */

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
//        if (!root) return {};
        vector<int> res{};
        stack<TreeNode *> s{};
        TreeNode *p = root;

        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                auto n = s.top();
                s.pop();
                res.push_back(n->val);
                p = n->right;
            }
        }
        return res;
    }
};

#endif //LEETCODE_BINARYTREEINORDERTRAVERSAL_H
