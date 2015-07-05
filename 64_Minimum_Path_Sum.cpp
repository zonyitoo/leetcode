#include <vector>
using std::vector;
#include <queue>
using std::queue;
#include <climits>
#include <cmath>
using std::min;

class Solution {
private:
    bool validate_pos(const vector<vector<int>> &grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid.front().size();
    }

public:
    int minPathSum(const vector<vector<int>> &grid) {
        if (grid.size() == 0)
            return 0;

        const static int mv_x[] = {0, 1};
        const static int mv_y[] = {1, 0};

        vector<vector<int>> minsum(grid.size(), vector<int>(grid.front().size(), INT_MAX));
        minsum[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                for (int k = 0; k < 2; ++k) {
                    int nx = i - mv_x[k];
                    int ny = j - mv_y[k];
                    if (validate_pos(grid, nx, ny)) {
                        int nsum = grid[i][j] + minsum[nx][ny];
                        minsum[i][j] = min(minsum[i][j], nsum);
                    }
                }
            }
        }

        return minsum.back().back();
    }
};
