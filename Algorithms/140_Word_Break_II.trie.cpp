#include "leetcode.hpp"

#include <cstring>
#include <iterator>
#include <algorithm>

class TireTree {
private:
    struct Node {
        Node *next[256];
        bool is_end;

        Node(): is_end(false) {
            for (size_t i = 0; i < 256; ++i) {
                next[i] = nullptr;
            }
        }

        Node(const Node& node): is_end(node.is_end) {
            for (size_t i = 0; i < 256; ++i) {
                if (node.next[i] != nullptr) {
                    this->next[i] = new Node(*node.next[i]);
                } else {
                    this->next[i] = nullptr;
                }
            }
        }

        ~Node() {
            for (size_t i = 0; i < 256; ++i) {
                if (this->next[i] != nullptr) {
                    delete this->next[i];
                }
            }
        }

        Node& operator=(const Node& rhs) {
            for (size_t i = 0; i < 256; ++i) {
                if (this->next[i] != nullptr) {
                    delete this->next[i];
                    this->next[i] = nullptr;
                }
            }

            for (size_t i = 0; i < 256; ++i) {
                if (rhs.next[i] != nullptr) {
                    this->next[i] = new Node(*rhs.next[i]);
                } else {
                    this->next[i] = nullptr;
                }
            }

            return *this;
        }
    };

public:
    TireTree() {
        this->root_ = new TireTree::Node();
    }

    ~TireTree() {
        delete this->root_;
    }

    TireTree(const TireTree& tt) {
        this->root_ = new TireTree::Node(*tt.root_);
    }

    TireTree& operator=(const TireTree& rhs) {
        delete this->root_;
        this->root_ = new TireTree::Node(*rhs.root_);
        return *this;
    }

    void insert(const string& s) {
        TireTree::Node *cur = this->root_;

        for (char c : s) {
            const size_t idx = static_cast<size_t>(c);

            if (cur->next[idx] == nullptr) {
                cur->next[idx] = new TireTree::Node();
            }

            cur = cur->next[idx];
        }

        cur->is_end = true;
    }

    template <typename InputIter, typename Callback>
    void searchAll(InputIter beg, InputIter end, Callback cb) const {
        TireTree::Node *cur = this->root_;

        InputIter itr = beg;
        for (; itr != end; ++itr) {
            const size_t idx = static_cast<size_t>(*itr);

            if (cur->is_end) {
                cb(itr);
            }

            if (cur->next[idx] == nullptr) {
                return;
            }

            cur = cur->next[idx];
        }

        if (cur->is_end) {
            cb(end);
        }
    }

    template <typename InputIter>
    bool search(InputIter beg, InputIter end, bool *possible = nullptr) const {
        TireTree::Node *cur = this->root_;

        while (beg != end) {
            const size_t idx = static_cast<size_t>(*beg);

            if (cur->next[idx] == nullptr) {
                if (possible != nullptr) {
                    *possible = false;
                }

                return false;
            }

            cur = cur->next[idx];

            ++beg;
        }

        if (possible != nullptr) {
            *possible = true;
        }

        return cur->is_end;
    }

    void clear() {
        for (size_t i = 0; i < 256; ++i) {
            if (this->root_->next[i] != nullptr) {
                delete this->root_->next[i];
                this->root_->next[i] = nullptr;
            }
        }
    }

private:
    Node *root_;
};

class Solution {
public:
    vector<string> wordBreak(const string& s, const unordered_set<string>& wordDict) {
        vector<string> result;
        if (wordDict.empty() || s.empty()) {
            return std::move(result);
        }

        TireTree tire;
        for (const string& word : wordDict) {
            tire.insert(word);
        }

        vector<bool> possible(s.size(), true);

        vector<string> stack;
        this->recursiveSolve(result, stack, possible, s.cbegin(), s, tire);

        return std::move(result);
    }

private:
    void recursiveSolve(vector<string>& result,
                        vector<string>& stack,
                        vector<bool>& possible,
                        string::const_iterator beg,
                        const string& s,
                        const TireTree& tire) const {
        const size_t idx = std::distance(s.cbegin(), beg);
        if (!possible[idx]) {
            return;
        }

        if (beg == s.cend()) {
            string s(stack[0]);
            for (size_t i = 1; i < stack.size(); ++i) {
                s.push_back(' ');
                s.append(stack[i]);
            }
            result.push_back(std::move(s));
            return;
        }

        bool is_possible = false;
        tire.searchAll(beg, s.cend(),
            [&](string::const_iterator e) {
                const size_t new_idx = std::distance(s.cbegin(), e);
                if (!possible[new_idx]) {
                    return;
                }

                is_possible = true;

                string sx;
                std::copy(beg, e, std::back_inserter(sx));
                stack.push_back(std::move(sx));
                this->recursiveSolve(result, stack, possible, e, s, tire);
                stack.pop_back();
            });

        possible[idx] = is_possible;
    }
};
