#include <vector>
#include <algorithm>
#include <limits>
using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, const vector<int>& nums) {
        if (nums.empty()) return 0;

        int sum = 0;
        size_t begin = 0, end = 0;
        int length = std::numeric_limits<int>::max();
        for (size_t i = 0; i < nums.size(); ++i, ++end) {
            sum += nums[i];

            while (sum >= s && begin <= end) {
                if (begin == end) return 1;

                length = std::min(length, static_cast<int>(end - begin + 1));

                sum -= nums[begin++];
            }
        }

        return length == std::numeric_limits<int>::max() ? 0 : length;
    }
};
