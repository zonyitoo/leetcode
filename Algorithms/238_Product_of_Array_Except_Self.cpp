#include <vector>
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        int left = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            left *= nums[i - 1];
            ans[i] *= left;
        }

        int right = 1;
        for (long i = nums.size() - 2; i >= 0; --i) {
            right *= nums[i + 1];
            ans[i] *= right;
        }

        return std::move(ans);
    }
};
