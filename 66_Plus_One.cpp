#include <vector>
using std::vector;
#include <algorithm>
using std::reverse;

class Solution {
public:
    vector<int> plusOne(const vector<int> &digits) {
        vector<int> result;
        bool carry = true;
        for (auto ritr = digits.rbegin(); ritr != digits.rend(); ++ritr) {
            int tmp = 0;
            if (carry) {
                carry = false;
                tmp += 1;
            }
            tmp += *ritr;
            if (tmp >= 10) {
                tmp -= 10;
                carry = true;
            }
            result.push_back(tmp);
        }
        if (carry) {
            result.push_back(1);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
