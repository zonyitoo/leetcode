#include <vector>
using std::vector;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

#include <iostream>
using std::cout;
using std::endl;
#include <cassert>
int main(int argc, char **argv) {
    assert(Solution().climbStairs(10) == 89);
    return 0;
}
