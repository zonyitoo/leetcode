#include <string>
using std::string;

class WordDictionary {
public:
    WordDictionary() {
        trie_root = new TrieNode();
    }

    ~WordDictionary() {
        this->clean(this->trie_root);
        delete this->trie_root;
    }

    // Adds a word into the data structure.
    void addWord(const string& word) {
        TrieNode *cur = trie_root;
        for (char c : word) {
            size_t idx = static_cast<size_t>(c - 'a');

            if (cur->next[idx] == nullptr) {
                cur->next[idx] = new TrieNode();
            }

            cur = cur->next[idx];
        }

        cur->is_end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(const string& word) const {
        return this->innerSearch(word, 0, this->trie_root);
    }

private:
    struct TrieNode {
        static const size_t NEXT_SIZE = 26;

        bool is_end;
        TrieNode *next[NEXT_SIZE]; // Only support ASCII lowercase letters

        TrieNode()
            : is_end(false) {
            for (TrieNode *&node : next) {
                node = nullptr;
            }
        }
    };

    void clean(TrieNode *node) const {
        if (node == nullptr) return;

        for (TrieNode *&n : node->next) {
            if (n != nullptr) {
                this->clean(n);
                delete n;
                n = nullptr;
            }
        }
    }

    // Could be optimized by using stack
    bool innerSearch(const string& word, size_t pos, TrieNode *node) const {
        if (pos == word.size()) {
            return node->is_end;
        }

        if (word[pos] == '.') {
            for (size_t i = 0; i < TrieNode::NEXT_SIZE; ++i) {
                if (node->next[i] == nullptr) continue;

                if (this->innerSearch(word, pos + 1, node->next[i])) {
                    return true;
                }
            }

        } else {
            size_t idx = static_cast<size_t>(word[pos] - 'a');
            if (node->next[idx] == nullptr) return false;
            return this->innerSearch(word, pos + 1, node->next[idx]);
        }

        return false;
    }

    TrieNode *trie_root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
