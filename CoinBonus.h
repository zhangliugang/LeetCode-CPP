//
// Created by August on 4/23/20.
//

#ifndef LEETCODE_COINBONUS_H
#define LEETCODE_COINBONUS_H

/**
 * LCP 05. 发 LeetCoin
 * https://leetcode-cn.com/problems/coin-bonus/
 */

#include <vector>

using namespace std;

class Solution {
private:
    struct Node{
        int64_t coin = 0;
        int subCount = 0;
        Node *parent;
        vector<Node *> child{};
        Node(): parent(nullptr){}
        void update(int c) {
            coin = coin + c;
            if (parent) {
                parent->update(c);
            }
        }
        void addSub() {
            subCount++;
            if (parent) {
                parent->addSub();
            }
        }
    };
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        vector<Node*> nodes{};
        vector<int> res{};
        for (int i = 0; i < n; ++i) {
            nodes.push_back(new Node());
        }
        for (auto &ls: leadership) {
            nodes[ls[0] - 1]->child.push_back(nodes[ls[1] - 1]);
            nodes[ls[1] - 1]->parent = nodes[ls[0] - 1];
            nodes[ls[1] - 1]->parent->addSub();
        }
        for (auto &op: operations) {
            if (op[0] == 1) {
                nodes[op[1] - 1]->update(op[2]);
            } else if (op[0] == 2) {
                Node *node = nodes[op[1] - 1];
                op2(node, op[2]);
                if (node->parent) {
                    node->parent->update(op[2] * (node->subCount + 1));
                }
            } else if (op[0] == 3) {
                res.push_back(nodes[op[1] - 1]->coin % 1000000007);
            }
        }
        return res;
    }

    void op2(Node *node, int coin) {
        node->coin = (node->coin + coin * (node->subCount + 1));
        for (auto &child: node->child) {
            op2(child, coin);
        }
    }
};

#endif //LEETCODE_COINBONUS_H
