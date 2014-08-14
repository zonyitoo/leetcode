#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
    int numDecodings(const string &s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i - 1] == '1')
                    || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                dp[i + 1] += dp[i - 1];
            }
            if (s[i] != '0') {
                dp[i + 1] += dp[i];
            }
        }
        return dp[s.size()];
    }
};

