#include <vector>
#include <tuple>
#include <algorithm>
#include <cstdlib>
using std::vector;
using std::tuple;

class Solution {
  public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        vector<tuple<int, int>> indices;

        for (size_t i = 0; i < nums.size(); ++i) {
            indices.push_back(std::make_tuple(i, nums[i]));
        }

        std::sort(indices.begin(), indices.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
            return std::get<1>(a) < std::get<1>(b);
        });

        for (size_t i = 1; i < indices.size(); ++i) {
            if (std::get<1>(indices[i]) == std::get<1>(indices[i - 1])) {
                int diff = std::get<0>(indices[i]) - std::get<0>(indices[i - 1]);
                if (std::abs(diff) <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};
