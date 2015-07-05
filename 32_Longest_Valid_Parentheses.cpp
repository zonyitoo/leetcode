#include <string>
using std::string;
#include <vector>
using std::vector;
#include <tuple>
using std::tuple;
using std::make_tuple;
using std::tie;
using std::get;
#include <stack>
using std::stack;

class SegmTree {
private:
    struct Node {
        int start, end;
        Node *left;
        Node *right;
        bool is_covered;
        Node(int start, int end)
            : start(start), end(end), left(nullptr), right(nullptr), is_covered(false) {}
    };
public:
    SegmTree(int start, int end)
        : root(new Node(start, end)) {
        __init_tree(root);
    }

    ~SegmTree() {
        __clear(root);
    }

    SegmTree(const SegmTree &st) = delete;
    SegmTree &operator=(const SegmTree &rhs) = delete;

    void insert(int start, int end) {
        __insert(root, start, end);
    }

    vector<tuple<int, int>> intervals() const {
        vector<tuple<int, int>> result;
        __intervals(result, root);
        return result;
    }

private:
    Node *root;

    void __init_tree(Node *r) {
        if (r->end - r->start <= 1) {
            return;
        }

        int mid = (r->start + r->end) / 2;
        r->left = new Node(r->start, mid);
        __init_tree(r->left);
        r->right = new Node(mid, r->end);
        __init_tree(r->right);
    }

    void __clear(Node *r) {
        if (r == nullptr) {
            return;
        }
        __clear(r->left);
        __clear(r->right);
        delete r;
    }

    void __intervals(vector<tuple<int, int>> &itvls, Node *r) const {
        if (r->is_covered) {
            if (itvls.empty()) {
                itvls.push_back(make_tuple(r->start, r->end));
            } else {
                int start, end;
                tie(start, end) = itvls.back();
                if (end == r->start) {
                    itvls.back() = make_tuple(start, r->end);
                } else {
                    itvls.push_back(make_tuple(r->start, r->end));
                }
            }
        } else {
            if (r->left != nullptr) {
                __intervals(itvls, r->left);
            }
            if (r->right != nullptr) {
                __intervals(itvls, r->right);
            }
        }
    }

    void __insert(Node *r, int start, int end) {
        if (r->start == start && r->end == end) {
            r->is_covered = true;
            return;
        }

        int mid = (r->start + r->end) / 2;
        if (start >= mid) {
            __insert(r->right, start, end);
        } else if (end <= mid) {
            __insert(r->left, start, end);
        } else {
            __insert(r->left, start, mid);
            __insert(r->right, mid, end);
        }

        if (r->left->is_covered && r->right->is_covered) {
            r->is_covered = true;
        }
    }
};

class Solution {
public:
    int longestValidParentheses(const string &str) {
        SegmTree tree(0, str.length() - 1);
        stack<tuple<char, int>> s;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                s.push(make_tuple(str[i], i));
            } else {
                if (s.empty()) {
                    continue;
                }
                char c;
                int idx;
                tie(c, idx) = s.top();
                if (c == '(') {
                    s.pop();
                    tree.insert(idx, i);
                } else {
                    s.push(make_tuple(str[i], i));
                }
            }
        }

        auto itvls = tree.intervals();
        if (itvls.empty()) {
            return 0;
        }

        int max_interval = 0;
        int cbeg, cend;
        tie(cbeg, cend) = itvls.front();
        for (int i = 1; i < itvls.size(); ++i) {
            int start, end;
            tie(start, end) = itvls[i];
            if (start != cend + 1) {
                int itvl = cend - cbeg + 1;
                if (max_interval < itvl) {
                    max_interval = itvl;
                }
                cbeg = start;
            }
            cend = end;
        }
        int itvl = cend - cbeg + 1;
        if (max_interval < itvl) {
            max_interval = itvl;
        }

        return max_interval;
    }
};

