#include <vector>
using std::vector;

class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;

        vector<int> st;
        solve(st, result, 0, 0, k, n);

        return std::move(result);
    }

  private:

    void solve(vector<int>& st, vector<vector<int>>& res, int choose, int sum, int k, int n) {
        if (st.size() == k) {
            if (sum == n) {
                res.push_back(st);
            }
            return;
        }

        for (int i = choose + 1; i < 10; ++i) {
            if (sum + i > n) {
                break;
            }

            st.push_back(i);
            solve(st, res, i, sum + i, k, n);
            st.pop_back();
        }
    }

};
