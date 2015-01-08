#include <vector>
using std::vector;
using std::swap;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> perm;
        for (int i = 0; i < n; ++i)
            perm.push_back(i);
        int sum = 0;
        __permutation(perm, 0, sum);
        return sum;
    }

private:
    void __permutation(vector<int> &perm, int begidx, int &sum) {
        if (begidx == perm.size() - 1) {
            ++sum;
            return;
        }

        __permutation(perm, begidx + 1, sum);
        for (int i = begidx + 1; i < perm.size(); ++i) {
            swap(perm[begidx], perm[i]);
            __permutation(perm, i, sum);
            swap(perm[begidx], perm[i]);
        }
    }
};
