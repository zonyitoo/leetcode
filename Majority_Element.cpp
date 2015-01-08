#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 因为题目中 Majority Element 在 num 中出现的次数肯定是最多的，
     * 所以每次循环，1 或 0 的个数中最多的那个肯定就属于那个 number
     */
    int majorityElement(const vector<int> &num) {
        int majority = 0;
        for (int pos = 0; pos < sizeof(int) * 8; ++pos) {
            int one = 0, zero = 0;
            for (auto &elem : num) {
                if ((elem & (1 << pos)) == 0) {
                    zero++;
                } else {
                    one++;
                }
            }

            if (one > zero) majority |= (1 << pos);
        }
        return majority;
    }
};
