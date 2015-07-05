#include <vector>
using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[i].size(); ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                const static int mv_x[] = { -1, 0};
                const static int mv_y[] = {0, -1};
                for (int k = 0; k < 2; ++k) {
                    int nx = i + mv_x[k];
                    int ny = j + mv_y[k];
                    if (nx >= 0 && nx < obstacleGrid.size() && ny >= 0 && ny < obstacleGrid[i].size()) {
                        dp[i][j] += dp[nx][ny];
                    }
                }
            }
        }
        return dp.back().back();
    }
};
