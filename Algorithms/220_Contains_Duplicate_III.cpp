#include <vector>
#include <tuple>
#include <cstdlib>
using std::vector;
using std::tuple;

class Solution {
  public:
    bool containsNearbyAlmostDuplicate(const vector<int>& nums, int k, int t) {
        vector<tuple<int, long>> indices;

        for (size_t i = 0; i < nums.size(); ++i) {
            indices.push_back(std::make_tuple(i, nums[i]));
        }

        std::sort(indices.begin(), indices.end(), [](const tuple<int, long>& a, const tuple<int, long>& b) {
            return std::get<1>(a) < std::get<1>(b);
        });

        for (size_t i = 0, j = 1; j < indices.size(); ++j) {
            int idx_left, idx_right;
            long val_left, val_right;

            std::tie(idx_left, val_left) = indices[i];
            std::tie(idx_right, val_right) = indices[j];

            long diff_val = std::abs(val_right - val_left);
            int diff_idx = std::abs(idx_right - idx_left);

            while (i < j && diff_val > t) {
                ++i;

                std::tie(idx_left, val_left) = indices[i];
                std::tie(idx_right, val_right) = indices[j];

                diff_val = std::abs(val_right - val_left);
                diff_idx = std::abs(idx_right - idx_left);
            }

            if (i < j && diff_val <= t) {

                int left = i, right = j;
                while (left < right && diff_idx > k) {
                    left++;

                    std::tie(idx_left, val_left) = indices[left];
                    std::tie(idx_right, val_right) = indices[right];

                    diff_val = std::abs(val_right - val_left);
                    diff_idx = std::abs(idx_right - idx_left);
                }

                if (left < right && diff_idx <= k) return true;
            }
        }

        return false;
    }
};
