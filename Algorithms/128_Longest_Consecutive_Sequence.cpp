#include <vector>
using std::vector;
#include <set>
using std::set;

class Solution {
public:
    int longestConsecutive(const vector<int> &num) {
        set<int> numset;
        for (auto &n : num) {
            numset.insert(n);
        }

        int ans = 0;
        while (!numset.empty()) {
            int tmp = *numset.begin();
            int cnt = 1;
            auto itr = numset.begin();
            numset.erase(itr);
            while ((itr = numset.find(++tmp)) != numset.end()) {
                numset.erase(itr);
                ++cnt;
            }
            if (cnt > ans) {
                ans = cnt;
            }
        }

        return ans;
    }
};
