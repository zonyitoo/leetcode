#include <vector>
#include <cmath>
#include <climits>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxProfit(const vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> ones(prices.size(), 0), twos(prices.size(), 0);
        int ans = prices.front();
        for (int i = 0; i < prices.size(); ++i) {
            ones[i] = prices[i] - ans;
            ans = min(ans, prices[i]);
        }

        ans = prices.back();
        for (int j = prices.size() - 1; j >= 0; --j) {
            twos[j] = ans - prices[j];
            ans = max(ans, prices[j]);
        }

        for (int i = 1; i < prices.size(); ++i) {
            ones[i] = max(ones[i], ones[i - 1]);
            twos[prices.size() - i - 1] = max(twos[prices.size() - i - 1], twos[prices.size() - i]);
        }

        ans = 0;
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ans, ones[i] + twos[i]);
        }

        return ans;
    }
};
