#include "leetcode.hpp"

#include <vector>
#include <limits>
#include <algorithm>
using std::vector;

class Solution {
public:
    int numSquares(int n) {
        if (n <= 1) {
            return n;
        }

        vector<int> dp(n + 1, std::numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            dp[i * i] = 1;
        }

        if (dp[n] != std::numeric_limits<int>::max()) {
            return dp[n];
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                const int prev = i - j * j;
                const int num = dp[prev] + 1;
                dp[i] = std::min(dp[i], num);
            }
        }

        return dp[n];
    }
};
