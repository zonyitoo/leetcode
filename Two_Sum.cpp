#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<int> twoSum(const vector<int> &numbers, int target) {
        vector<int> indexes;
        for (int i = 0; i < numbers.size(); ++i) {
            indexes.push_back(i);
        }

        sort(indexes.begin(), indexes.end(), [&numbers](const int &a, const int &b) {
            return numbers[a] < numbers[b];
        });

        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int s = numbers[indexes[left]] + numbers[indexes[right]];
            if (s == target) {
                int ind1 = indexes[left] + 1, ind2 = indexes[right] + 1;
                return ((ind1 < ind2) ? vector<int>({ind1, ind2}) : vector<int>({ind2, ind1}));
            } else if (s > target) {
                --right;
            } else {
                ++left;
            }
        }

        // Never reach here!!
        return { -1, -1};
    }
};
