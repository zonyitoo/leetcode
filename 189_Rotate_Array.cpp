#include <algorithm>
#include <vector>
using std::vector;
using std::reverse;

class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
        int steps = nums.size() - k % nums.size();

        reverse(nums.begin(), nums.begin() + steps);
        reverse(nums.begin() + steps, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
