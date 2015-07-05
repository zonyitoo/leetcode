#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int m = num[0];
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] < m) {
                m = num[i];
                break;
            }
        }
        return m;
    }
};
