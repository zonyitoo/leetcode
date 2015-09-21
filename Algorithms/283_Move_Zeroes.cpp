#include "leetcode.hpp"

#include <algorithm>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t zero_begin = 0;
        while (nums[zero_begin] != 0) zero_begin++;

        for (size_t i = zero_begin + 1; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                for (size_t j = i; j > zero_begin; --j) {
                    std::swap(nums[j], nums[j - 1]);
                }
                zero_begin++;
            }
        }
    }
};
