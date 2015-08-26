#include <vector>
using std::vector;

class Solution {
public:
    vector<int> majorityElement(const vector<int>& nums) {
        if (nums.size() <= 1) return nums;

        int cnt1 = 0, cnt2 = 0;
        int maj1 = 0, maj2 = 0;

        for (int n : nums) {
            if (cnt1 == 0) {
                cnt1 += 1;
                maj1 = n;
            } else if (maj1 == n) {
                cnt1 += 1;
            } else if (cnt2 == 0) {
                cnt2 += 1;
                maj2 = n;
            } else if (maj2 == n) {
                cnt2 += 1;
            } else {
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }

        // Ensure there has two majority elements
        cnt1 = cnt2 = 0;
        for (int n : nums) {
            if (maj1 == n) {
                cnt1 += 1;
            } else if (maj2 == n) {
                cnt2 += 1;
            }
        }

        vector<int> ans;
        if (cnt1 > nums.size() / 3) ans.push_back(maj1);
        if (cnt2 > nums.size() / 3) ans.push_back(maj2);
        return ans;
    }
};
