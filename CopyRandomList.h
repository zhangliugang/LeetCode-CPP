//
// Created by August on 4/22/20.
//

#ifndef LEETCODE_COPYRANDOMLIST_H
#define LEETCODE_COPYRANDOMLIST_H

/**
 * 138. 复制带随机指针的链表
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head;
        while (p) {
            Node *n = new Node(p->val);
            n->next = p->next;
            p->next = n;
            p = n->next;
        }
        p = head;
        while (p) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        Node *p2 = head->next;
        Node *ans = p2;
        while (p2->next) {
            p->next = p->next->next;
            p = p->next;
            p2->next = p2->next->next;
            p2 = p2->next;
        }
        p->next = nullptr;
        return ans;
    }
};

#endif //LEETCODE_COPYRANDOMLIST_H
