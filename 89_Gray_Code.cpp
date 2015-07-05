#include <vector>
using std::vector;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v(1, 0);
        for (int pos = 0; pos < n; ++pos) {
            vector<int> tmp;
            for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr) {
                tmp.push_back(*itr);
            }
            for (vector<int>::reverse_iterator itr = v.rbegin(); itr != v.rend(); ++itr) {
                tmp.push_back((*itr) | (1 << pos));
            }
            v = tmp;
        }

        return v;
    }
};
