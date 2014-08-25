#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> result;

        for (int i = 0; i < static_cast<int>(num.size()) - 3; ++i) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < static_cast<int>(num.size()) - 2; ++j) {
                if (j > i + 1 && num[j] == num[j - 1]) {
                    continue;
                }

                int left = j + 1, right = num.size() - 1;
                while (left < right) {
                    if (left > j + 1 && num[left] == num[left - 1]) {
                        ++left;
                        continue;
                    }

                    if (right < num.size() - 1 && num[right] == num[right + 1]) {
                        --right;
                        continue;
                    }

                    int s = num[i] + num[j] + num[left] + num[right];
                    if (s == target) {
                        result.push_back(vector<int> {num[i], num[j], num[left], num[right]});
                        ++left;
                    } else if (s < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};
