class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101] = {0}; // m and n will be at most 100
        dp[0][0] = 1;
        static const int mv_x[] = {1, 0};
        static const int mv_y[] = {0, 1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 2; ++k) {
                    int px = i - mv_x[k];
                    int py = j - mv_y[k];
                    if (is_valid(px, py, m, n)) {
                        dp[i][j] += dp[px][py];
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }

private:
    bool is_valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};
