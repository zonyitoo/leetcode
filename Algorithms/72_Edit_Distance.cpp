#include <string>
#include <climits>
#include <cstdint>
#include <vector>
#include <cmath>
using std::string;
using std::vector;
using std::min;

class Solution {
public:
    int minDistance(const string &word1, const string &word2) {
        vector<vector<int>> remember(word1.size(), vector<int>(word2.size(), -1));
        return dfs(word1, 0, word2, 0, remember);
    }

private:
    int dfs(const string &word1, int idx1, const string &word2, int idx2,
            vector<vector<int>> &remember) {
        if (idx2 == word2.size()) {
            return word1.size() - idx1;
        }

        if (idx1 == word1.size()) {
            return word2.size() - idx2;
        }

        if (remember[idx1][idx2] != -1) {
            return remember[idx1][idx2];
        }

        if (word1[idx1] == word2[idx2]) {
            return remember[idx1][idx2] = dfs(word1, idx1 + 1, word2, idx2 + 1, remember);
        } else {
            int del = dfs(word1, idx1 + 1, word2, idx2, remember) + 1;
            int ins = dfs(word1, idx1, word2, idx2 + 1, remember) + 1;
            int rep = dfs(word1, idx1 + 1, word2, idx2 + 1, remember) + 1;

            return remember[idx1][idx2] = min(ins, min(rep, del));
        }
    }
};
