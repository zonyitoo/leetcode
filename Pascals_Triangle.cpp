#include <vector>
using std::vector;
using std::move;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        result.push_back(vector<int>(1, 1));
        for (int i = 0; i < numRows - 1; ++i) {
            vector<int> tmp(1, 1);
            for (int j = 0; j < result[i].size() - 1; ++j) {
                tmp.push_back(result[i][j] + result[i][j + 1]);
            }
            tmp.push_back(1);
            result.push_back(move(tmp));
        }
        return move(result);
    }
};
