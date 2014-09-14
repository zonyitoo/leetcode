#include <vector>
#include <cmath>
using std::vector;
using std::max;

class Solution {
public:
    int candy(const vector<int> &ratings) {
        int ans = 0;
        if (ratings.empty()) {
            return ans;
        }

        vector<int> dp(ratings.size(), 1);
        for (int i = 1; i < dp.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }

        ans = dp.back();
        for (int i = dp.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                dp[i] = max(dp[i], dp[i + 1] + 1);
            }

            ans += dp[i];
        }

        return ans;
    }
};
