#ifndef __LEETCODE_H__
#define __LEETCODE_H__

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::queue;
using std::string;
using std::cout;
using std::endl;
using std::unordered_map;
using std::unordered_set;

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

std::ostream& operator<<(std::ostream& os, TreeNode *node) {
    std::queue<TreeNode *> q;
    q.push(node);
    os << "{";
    bool is_first = true;
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (!is_first) {
            os << ",";
        } else {
            is_first = false;
        }
        if (cur == nullptr) {
            os << "#";
        } else {
            os << cur->val;
            if (cur->left != nullptr || cur->right != nullptr) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
    }
    os << "}";
    return os;
}

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

std::ostream& operator<<(std::ostream& os, ListNode *node) {
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

void delete_list(ListNode *lst) {
    while (lst != nullptr) {
        ListNode *cur = lst;
        lst = lst->next;
        delete cur;
    }
}

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x): label(x) {}
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(nullptr), random(nullptr) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::ostream& operator<<(std::ostream& os, const Interval& interval) {
    os << "[" << interval.start << "," << interval.end << "]";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto& val : v) {
        os << std::boolalpha << val << ",";
    }
    os << "]";
    return os;
}

#endif
