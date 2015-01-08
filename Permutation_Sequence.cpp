#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using std::string;
using std::next_permutation;
using std::prev_permutation;
using std::vector;
using std::stringstream;
using std::move;
using std::reverse;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> tmp;
        for (int i = 1; i <= n; ++i)
            tmp.push_back(i);

        long long s = fac(n);
        while (k > s) {
            k -= s;
        }

        if (k > s / 2) {
            reverse(tmp.begin(), tmp.end());
            k = s - k;
            while (k--) {
                prev_permutation(tmp.begin(), tmp.end());
            }
        } else {
            while (--k) {
                next_permutation(tmp.begin(), tmp.end());
            }
        }

        stringstream ss;
        for (auto &num : tmp) {
            ss << num;
        }
        return move(ss.str());
    }

private:
    long long fac(int n) {
        long long result = n;
        while (--n) {
            result *= n;
        }
        return result;
    }
};
