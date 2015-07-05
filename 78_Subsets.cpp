#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> S) {
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        vector<int> stack;
        result.push_back(stack);
        solve(S.begin(), S.end(), stack, result);
        return result;
    }

private:
    void solve(vector<int>::const_iterator begin, vector<int>::const_iterator end,
               vector<int> &stack, vector<vector<int>> &result) {
        while (begin != end) {
            stack.push_back(*begin);
            result.push_back(stack);
            solve(++begin, end, stack, result);
            stack.pop_back();
        }
    }
};

