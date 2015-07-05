#include <vector>
#include <algorithm>
using std::vector;

class Solution {
  public:
    int rob(const vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            dp[i + 1] = std::max(dp[i - 1] + nums[i],
                                 dp[i]);
        }

        return dp.back();
    }
};
