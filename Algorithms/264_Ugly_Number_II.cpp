#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.reserve(n);

        dp.push_back(1);
        for (int i2 = 0, i3 = 0, i5 = 0; dp.size() < n;) {
            const int m2 = dp[i2] * 2;
            const int m3 = dp[i3] * 3;
            const int m5 = dp[i5] * 5;
            const int minval = std::min({m2, m3, m5});
            dp.push_back(minval);

            if (m2 == minval) ++i2;
            if (m3 == minval) ++i3;
            if (m5 == minval) ++i5;
        }

        return dp[n - 1];
    }
};
