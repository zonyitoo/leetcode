#include <vector>
#include <queue>
#include <tuple>
using std::vector;
using std::queue;
using std::tuple;

class Solution {
  public:
    int numIslands(const vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    queue<tuple<int, int>> q;
                    q.push(std::make_tuple(i, j));
                    visited[i][j] = true;
                    while (!q.empty()) {
                        int x, y;
                        std::tie(x, y) = q.front();
                        q.pop();

                        const int mv_x[] = {0, 0, -1, 1};
                        const int mv_y[] = {1, -1, 0, 0};

                        for (int p = 0; p < 4; ++p) {
                            int nx = x + mv_x[p];
                            int ny = y + mv_y[p];

                            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[i].size()
                                    && grid[nx][ny] == '1' && !visited[nx][ny]) {
                                q.push(std::make_tuple(nx, ny));
                                visited[nx][ny] = true;
                            }
                        }
                    }

                    ++count;
                }
            }
        }

        return count;
    }
};
