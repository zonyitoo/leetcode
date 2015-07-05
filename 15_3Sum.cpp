#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> result;

        for (int i = 0; i < num.size(); ++i) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }

            int left = i + 1, right = static_cast<int>(num.size()) - 1;
            while (left < right) {
                if (left > i + 1 && num[left] == num[left - 1]) {
                    ++left;
                    continue;
                }

                if (right < static_cast<int>(num.size()) - 1 && num[right] == num[right + 1]) {
                    --right;
                    continue;
                }

                int s = num[i] + num[left] + num[right];
                if (s == 0) {
                    result.emplace_back(vector<int> {num[i], num[left], num[right]});
                    ++left;
                } else if (s < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return result;
    }
};
