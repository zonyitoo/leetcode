#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        vector<int>::size_type left = 0, right = num.size() - 1;
        while (left < right) {
            auto mid = (left + right) / 2;
            auto lmid = mid, rmid = mid;
            while (lmid > left && num[lmid - 1] == num[mid]) --lmid;
            while (rmid < right && num[rmid + 1] == num[mid]) ++rmid;

            bool is_incleft = false, is_decright = false;
            if (lmid == 0 || num[lmid] > num[lmid - 1]) {
                is_incleft = true;
            }

            if (rmid == num.size() - 1 || num[rmid] > num[rmid + 1]) {
                is_decright = true;
            }

            if (is_incleft && is_decright) return mid;
            if (is_incleft && !is_decright) {
                left = rmid + 1;
            } else {
                right = lmid - 1;
            }
        }

        return left;
    }
};
