#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <cassert>

class Solution {
public:
    bool searchMatrix(const vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }

        int row = matrix.size() - 1, prevrow = 0;
        while (prevrow + 1 <= row) {
            int mid = (row + prevrow) / 2;
            if (matrix[mid].back() == target) {
                return true;
            } else if (target < matrix[mid].back()) {
                row = mid;
            } else {
                prevrow = mid + 1;
            }
        }

        int left = 0, right = matrix[row].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (target < matrix[row][mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1}, {2, 3}
    };

    assert(Solution().searchMatrix(matrix, 2) == true);

    matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    assert(Solution().searchMatrix(matrix, 10) == true);

    return 0;
}
