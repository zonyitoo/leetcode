#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::move;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        if (num.empty()) {
            return result;
        }
        vector<int> stack;
        this->__solve(result, stack, num, 0, 0, target);
        return move(result);
    }

private:
    void __solve(vector<vector<int>> &result, vector<int> &stack,
                 const vector<int> &num, int idx, int cursum, int target) {
        if (cursum == target) {
            result.emplace_back(stack);
            return;
        }
        if (idx >= num.size()) {
            return;
        }

        stack.push_back(num[idx]);
        int last = num[idx];
        this->__solve(result, stack, num, idx + 1, cursum + num[idx], target);
        stack.pop_back();
        for (int i = idx + 1; i < num.size(); ++i) {
            if (cursum + num[i] > target) {
                break;
            }

            if (num[i] != last) {
                last = num[i];
                stack.push_back(num[i]);
                this->__solve(result, stack, num, i + 1, cursum + num[i], target);
                stack.pop_back();
            }
        }
    }
};
