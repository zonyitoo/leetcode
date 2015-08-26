#include <vector>
using std::vector;

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        for (int beg_row = 0, end_row = matrix.size() - 1, beg_col = 0, end_col = matrix[0].size() - 1;
                beg_row <= end_row && beg_col <= end_col;
                ++beg_row, ++beg_col) {

            while (end_row >= beg_row && matrix[end_row][beg_col] > target) { --end_row; }
            if (end_row >= beg_row && matrix[end_row][beg_col] == target) {
                return true;
            }

            while (end_col >= beg_col && matrix[beg_row][end_col] > target) { --end_col; }
            if (end_col >= beg_col && matrix[beg_row][end_col] == target) {
                return true;
            }
        }

        return false;
    }
};
