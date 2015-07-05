#include <vector>
#include <algorithm>
using std::vector;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return true;
        }

        return false;
    }
};
