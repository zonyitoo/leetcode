#include <string>
#include <unordered_set>
#include <climits>
#include <cstdint>
#include <cmath>
using std::unordered_set;
using std::string;
using std::min;

class Tire {
private:
    struct Node {
        Node *next[UCHAR_MAX] = {0};
        bool isEnd = false;
    };

public:
    Tire()
        : root(new Node) {}

    ~Tire() {
        __clear(root);
        delete root;
    }

    void addWord(const string &word) {
        Node *cur = root;
        for (uint8_t c : word) {
            if (cur->next[c] == nullptr) {
                cur->next[c] = new Node;
            }
            cur = cur->next[c];
        }
        cur->isEnd = true;
    }

    bool hasWord(const string &word) {
        Node *cur = root;
        for (uint8_t c : word) {
            if (cur->next[c] == nullptr) {
                return false;
            }
            cur = cur->next[c];
        }
        return cur->isEnd;
    }

    int ladderLength(const string &start, const string &end) {
        if (start == end) {
            return 0;
        }
        string curstring = start;
        return dfsLadderLength(curstring, end);
    }

private:
    Node *root;

    void __clear(Node *r) {
        for (Node *&pnt : r->next) {
            if (pnt != nullptr) {
                __clear(pnt);
                delete pnt;
                pnt = nullptr;
            }
        }
    }

    int dfsLadderLength(string &curstring, const string &end) {
        if (curstring == end) {
            return 0;
        }
        printf("%s\n", curstring.c_str());

        int ans = INT_MAX;
        for (int i = 0; i < curstring.size(); ++i) {
            Node *curnode = root;
            bool valid = true;
            for (int j = 0; j < i; ++j) {
                if (curnode->next[curstring[static_cast<uint8_t>(j)]] == nullptr) {
                    valid = false;
                    break;
                }
                curnode = curnode->next[static_cast<uint8_t>(curstring[j])];
            }
            if (!valid)
                continue;

            printf("HERE\n");
            getchar();

            char tmp = curstring[i];
            for (int n = 0; n < UCHAR_MAX; ++n) {
                if (curnode->next[n] != nullptr && n != tmp) {
                    printf("curnode->next[%c]\n", n);
                    curstring[i] = static_cast<char>(n);

                    Node *cnode = curnode->next[n];
                    bool valid = true;
                    for (int k = i + 1; k < curstring.size(); ++k) {
                        if (cnode->next[static_cast<uint8_t>(curstring[k])] == nullptr) {
                            valid = false;
                            break;
                        }
                        cnode = cnode->next[static_cast<uint8_t>(curstring[k])];
                    }
                    if (!valid)
                        continue;

                    ans = min(ans, dfsLadderLength(curstring, end) + 1);
                }
            }
            curstring[i] = tmp;
        }
        return ans;
    }
};

class Solution {
public:
    int ladderLength(const string &start, const string &end, const unordered_set<string> &dict) {
        Tire tire;
        for (const string &s : dict) {
            tire.addWord(s);
        }
        return tire.ladderLength(start, end);
    }
};

#include <iostream>
using namespace std;
int main() {
    Solution s;
    cout << s.ladderLength("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << endl;
    return 0;
}
