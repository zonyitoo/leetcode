#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int hIndex(vector<int>& citations) const {
        if (citations.empty()) {
            return 0;
        }

        sort(citations.begin(), citations.end(), [](const int& a, const int& b) { return a > b; });

        for (size_t i = 1; i <= citations.size(); ++i) {
            if (i == citations[i - 1]) {
                return i;
            } else if (i > citations[i - 1]) {
                return i - 1;
            }
        }

        return citations.size();
    }
};
