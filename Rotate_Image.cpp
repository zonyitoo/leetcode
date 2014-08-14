#include <vector>
using std::vector;

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

