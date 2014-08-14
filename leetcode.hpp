#ifndef __LEETCODE_H__
#define __LEETCODE_H__

#include <iostream>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

std::ostream &operator<<(std::ostream &os, ListNode *node) {
    os << "[";
    if (node != nullptr) {
        os << node->val;
        node = node->next;
    }
    while (node != nullptr) {
        os << "," << node->val;
        node = node->next;
    }
    os << "]";
    return os;
}

template <typename Iterator>
ListNode *generate_list(Iterator beg, Iterator end) {
    ListNode *head = nullptr;
    ListNode **cur = &head;
    while (beg != end) {
        *cur = new ListNode(*beg);
        cur = &(*cur)->next;
        ++beg;
    }
    return head;
}

#endif
