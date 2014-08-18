#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::copy;
using std::back_inserter;

class Solution {
public:
    int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
        if (gas.size() == 0) {
            return -1;
        }

        vector<int> g, c;

        copy(gas.begin(), gas.end(), back_inserter(g));
        copy(gas.begin(), gas.end(), back_inserter(g));

        copy(cost.begin(), cost.end(), back_inserter(c));
        copy(cost.begin(), cost.end(), back_inserter(c));

        int start = 0, stop = 0, remain = g[0];
        while (stop < g.size()) {
            remain -= c[stop++];
            while (remain < 0) {
                remain += c[start] - g[start];
                start++;
            }

            if (stop == g.size()) {
                break;
            }

            if (stop - start == gas.size()) {
                return start;
            }

            remain += g[stop];
        }

        return -1;
    }
};
