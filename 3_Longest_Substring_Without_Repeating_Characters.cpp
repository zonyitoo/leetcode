#include <string>
#include <cmath>
using std::string;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        int remember[256];
        memset(remember, 0xff, sizeof(remember));

        int longest = 0, length = 0, start = 0;
        for (int idx = 0; idx < s.size(); ++idx) {
            if (remember[s[idx]] != -1) {
                longest = max(longest, length);
                length = idx - remember[s[idx]] - 1;
                for (int i = remember[s[idx]]; i >= start; --i) {
                    remember[s[i]] = -1;
                }
                start = idx - length;
            }

            remember[s[idx]] = idx;
            ++length;
        }
        return max(longest, length);
    }
};
