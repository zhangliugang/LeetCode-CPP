//
// Created by August on 4/3/20.
//

#ifndef LEETCODE_MERGESORTEDLIST_H
#define LEETCODE_MERGESORTEDLIST_H

/**
 * 23. 合并K个排序链表
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/
 */

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MergeSortedList {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        else if (lists.size() == 1) return lists[0];
        else if (lists.size() == 2) return mergeTwo(lists[0], lists[1]);
        else {
            int c = lists.size() / 2;

            vector<ListNode*> v1(lists.begin(), lists.begin() + c);
            vector<ListNode*> v2(lists.begin() + c, lists.end());

            return mergeTwo(mergeKLists(v1), mergeKLists(v2));
        }
    }

    ListNode* mergeTwo(ListNode *l1, ListNode * l2) {
        ListNode res = ListNode(0), *p = &res;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
        return res.next;
    }
};

#endif //LEETCODE_MERGESORTEDLIST_H
