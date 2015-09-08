#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        // x = n[1] ^ n[2] ^ ... ^ n[n]
        // x = (n[1] + n[2] + ... + n[n])
        int x = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            x ^= nums[i];
        }

        // x ^ 0 ^ 1 ^ ... ^ n
        // (0 + 1 + ... + n) - x
        for (int i = 0; i <= static_cast<int>(nums.size()); ++i) {
            x ^= i;
        }

        return x;
    }
};
