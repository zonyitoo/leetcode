#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> buf;
        solve(result, buf, n, 1, k);
        return result;
    }

    void solve(vector<vector<int>> &result, vector<int> &buf, int n, int current, int k) {
        if (buf.size() == k) {
            result.push_back(buf);
            return;
        }

        while (current <= n) {
            buf.push_back(current);
            solve(result, buf, n, ++current, k);
            buf.pop_back();
        }
    }
};

int main() {
    auto ret = Solution().combine(4, 3);
    cout << "[" << endl;
    for (auto &comb : ret) {
        cout << "\t[";
        auto itr = comb.begin();
        if (itr != comb.end())
            cout << *itr;
        ++itr;
        while (itr != comb.end()) {
            cout << "," << *itr;
            ++itr;
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
    return 0;
}
