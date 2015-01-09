#include <vector>
using namespace std;

class Solution {
public:
    int findMin(const vector<int> &num) {
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] < num[i - 1]) return num[i];
        }
        return num[0];
    }
};
