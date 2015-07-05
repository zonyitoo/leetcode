#include <string>
using std::string;
using std::move;

class Solution {
public:
    string convert(const string &s, int nRows) {
        if (nRows <= 1) {
            return s;
        }
        string ans;
        int gaps = 2 * nRows - 2;
        for (int line = 0; line < nRows; ++line) {
            for (int idx = line; idx < s.size(); idx += gaps) {
                ans.push_back(s[idx]);
                if (line != 0 && line != nRows - 1 && idx + gaps - 2 * line < s.size()) {
                    ans.push_back(s[idx + gaps - 2 * line]);
                }
            }
        }
        return move(ans);
    }
};
