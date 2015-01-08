#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <climits>

#include <iostream>
using namespace std;

class Solution {
public:
    int maximumGap(const vector<int> &num) {
        if (num.size() < 2) return 0;

        int max_elem = num[0], min_elem = num[0];
        for (int i = 1; i < num.size(); ++i) {
            max_elem = max(max_elem, num[i]);
            min_elem = min(min_elem, num[i]);
        }

        vector<tuple<int, int>> bucket((max_elem - min_elem) / (num.size() - 1), make_tuple(INT_MAX, INT_MIN));

        for (auto &elem : num) {
            int loc = (elem - min_elem) / bucket.size();
            int maxv, minv;
            tie(minv, maxv) = bucket[loc];
            maxv = max(maxv, elem);
            minv = min(minv, elem);
            bucket[loc] = make_tuple(minv, maxv);
        }

        int gap = 0;
        for (int i = 0, j; i < bucket.size(); ++i) {
            int lmaxv, lminv, rmaxv, rminv;
            tie(lminv, lmaxv) = bucket[i];
            if (lmaxv == INT_MIN || lminv == INT_MAX) {
                continue;
            }

            j = i + 1;
            while (j < bucket.size()) {
                tie(rminv, rmaxv) = bucket[j];
                if (rminv != INT_MAX) break;
                ++j;
            }

            if (j == bucket.size()) break;

            gap = max(gap, rminv - lmaxv);

            i = j;
        }

        return gap;
    }
};

#include <iostream>
int main() {
    vector<int> v {15252, 16764, 27963, 7817, 26155, 20757, 3478, 22602, 20404, 6739, 16790, 10588, 16521, 6644, 20880, 15632, 27078, 25463, 20124, 15728, 30042, 16604, 17223, 4388, 23646, 32683, 23688, 12439, 30630, 3895, 7926, 22101, 32406, 21540, 31799, 3768, 26679, 21799, 23740};
    cout << Solution().maximumGap(v) << endl;
    return 0;
}
