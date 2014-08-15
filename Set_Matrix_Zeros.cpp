#include <vector>
using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;

        // Basic idea is to store info in first col and row
        bool first_row_has_zero = false, first_col_has_zero = false;
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                first_row_has_zero = true;
                break;
            }
        }
        for (int j = 0; j < matrix.size(); ++j) {
            if (matrix[j][0] == 0) {
                first_col_has_zero = true;
                break;
            }
        }

        // Store information
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // Set zeros
        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_row_has_zero) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
        if (first_col_has_zero) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
