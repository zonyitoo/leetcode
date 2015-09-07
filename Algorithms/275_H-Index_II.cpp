#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int hIndex(const vector<int>& citations) {
        if (citations.empty()) {
            return 0;
        }

        int left = 0, right = citations.size() - 1;
        int last_possible = 0;
        while (left <= right) {
            const int mid = (static_cast<long>(left) + static_cast<long>(right)) / 2;
            const int posb_h = citations.size() - mid;
            if (citations[mid] == posb_h) {
                return posb_h;
            }

            if (citations[mid] > posb_h) {
                last_possible = std::max(posb_h, last_possible);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return last_possible;
    }
};
