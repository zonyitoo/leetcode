#include "leetcode.hpp"

class Solution {
public:
    vector<int> singleNumber(const vector<int>& nums) {
        int combination = 0;
        for (int n : nums) {
            combination ^= n;
        }

        const int first_bit = combination & ~(combination - 1);

        int num1 = 0, num2 = 0;
        for (int n : nums) {
            if ((n & first_bit) != 0) {
                num1 ^= n;
            } else {
                num2 ^= n;
            }
        }

        return {num1, num2};
    }
};
