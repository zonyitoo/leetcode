#include <vector>
using std::vector;
using std::move;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(1, 1);
        while (rowIndex--) {
            vector<int> tmp(result.size() + 1, 1);
            for (int i = 1; i < result.size(); ++i) {
                tmp[i] = (result[i] + result[i - 1]);
            }
            result = move(tmp);
        }
        return move(result);
    }
};
