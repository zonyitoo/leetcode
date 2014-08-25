#include <string>
#include <vector>
#include <climits>
#include <cmath>
using std::string;
using std::vector;
using std::min;

class Solution {
public:
    int minCut(const string &s) {
        if (s.empty()) {
            return 0;
        }

        vector<vector<int>> palin_next(s.size());
        for (int i = 0; i < s.size(); ++i) {
            for (int step = 0; step <= 1; ++step) {
                int left = i, right = i + step;
                while (left >= 0 && right < s.size()) {
                    if (s[left] == s[right]) {
                        palin_next[left].push_back(right);
                    } else {
                        break;
                    }
                    --left, ++right;
                }
            }
        }

        vector<int> remember(s.size(), -1);
        return dfsSolve(remember, palin_next, 0);
    }

private:
    int dfsSolve(vector<int> &remember, const vector<vector<int>> &palin_next, int curidx) {
        if (curidx >= remember.size()) {
            return -1;
        }

        if (remember[curidx] != -1) {
            return remember[curidx];
        }

        int mini = INT_MAX;
        for (const auto &item : palin_next[curidx]) {
            mini = min(mini, dfsSolve(remember, palin_next, item + 1) + 1);
        }

        return remember[curidx] = mini;
    }
};
