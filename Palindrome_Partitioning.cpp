#include <vector>
#include <string>
using std::vector;
using std::string;
using std::move;

class Solution {
public:
    vector<vector<string>> partition(const string &s) {
        vector<vector<string>> ans;
        if (s.empty()) {
            return move(ans);
        }

        vector<vector<bool>> is_pali;
        for (int i = 0; i < s.size(); ++i) {
            vector<bool> pali(s.size() - i + 1, false);
            is_pali.push_back(move(pali));
        }

        for (int i = 0; i < s.size(); ++i) {
            for (int beg = i, offset = 0; offset <= 1; ++offset) {
                int left = beg, right = offset;
                while (left >= 0 && right + left < s.size()) {
                    if (s[left] == s[right + left]) {
                        is_pali[left][right] = true;
                    } else {
                        break;
                    }
                    --left;
                    right += 2;
                }
            }
        }
        vector<string> stack;
        dfs(ans, is_pali, stack, s, 0);
        return move(ans);
    }

private:
    void dfs(vector<vector<string>> &ans, const vector<vector<bool>> &is_pali, vector<string> &stack,
             const string &s, int idx) {
        if (idx == s.size()) {
            ans.push_back(stack);
            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            if (is_pali[idx][i - idx]) {
                stack.push_back(move(s.substr(idx, i - idx + 1)));
                dfs(ans, is_pali, stack, s, i + 1);
                stack.pop_back();
            }
        }
    }
};
