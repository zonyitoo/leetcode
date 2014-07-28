#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for (int layer = 0; layer < matrix.size() / 2; ++layer) {
            int begin = layer;
            int end = matrix.size() - 1 - begin;
            for (int i = begin; i < end; ++i) {
                int t = matrix[begin][i];
                int r = matrix[i][end];
                int b = matrix[end][matrix.size() - 1 - i];
                int l = matrix[matrix.size() - 1 - i][begin];

                matrix[begin][i] = l;
                matrix[i][end] = t;
                matrix[end][matrix.size() - 1 - i] = r;
                matrix[matrix.size() - 1 - i][begin] = b;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    Solution().rotate(matrix);
    for (int i = 0; i < matrix.size(); ++ i) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); ++ j) {
            cout << matrix[i][j] << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
