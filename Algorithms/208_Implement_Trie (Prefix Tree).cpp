#include <string>
#include <cstring>
using std::string;

class TrieNode {
  public:
    // Initialize your data structure here.
    TrieNode()
        : nexts{0}
        , is_end(false) {}

    TrieNode* nexts[26];
    bool is_end;
};

class Trie {
  public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear_node(this->root);
    }

    // Inserts a word into the trie.
    void insert(const string& word) {
        TrieNode* node = this->root;
        for (char c : word) {
            int idx = static_cast<int>(c - 'a');

            if (node->nexts[idx] == nullptr) {
                node->nexts[idx] = new TrieNode();
            }

            node = node->nexts[idx];
        }

        node->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(const string& word) {
        TrieNode* node = this->root;
        for (char c : word) {
            int idx = static_cast<int>(c - 'a');

            if (node->nexts[idx] == nullptr) {
                return false;
            }

            node = node->nexts[idx];
        }

        return node->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(const string& prefix) {
        TrieNode* node = this->root;
        for (char c : prefix) {
            int idx = static_cast<int>(c - 'a');

            if (node->nexts[idx] == nullptr) {
                return false;
            }

            node = node->nexts[idx];
        }

        return true;
    }

  private:
    TrieNode* root;

    void clear_node(TrieNode* r) {
        if (r == nullptr) return;

        for (size_t i = 0; i < 26; ++i) {
            if (r->nexts[i] != nullptr) {
                clear_node(r->nexts[i]);
            }
        }

        delete r;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
