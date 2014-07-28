#include <vector>
using std::vector;
#include <queue>
using std::queue;
#include <climits>

class Solution {
private:
    struct Node {
        int x, y;
        int sum;
        Node(int x, int y, int sum)
            : x(x), y(y), sum(sum) {}
    };

    bool validate_pos(const vector<vector<int> > &grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
public:
    int minPathSum(const vector<vector<int> > &grid) {
        if (grid.size() == 0)
            return 0;
        int minSum = INT_MAX;
        queue<Node> q;

        static const int mov_x[] = {1, 0};
        static const int mov_y[] = {0, 1};

        q.push(Node(0, 0, grid[0][0]));
        while (!q.empty()) {
            Node cur = q.front();
            q.pop();
            if (cur.x == grid.size() && cur.y == grid[0].size() && cur.sum < minSum) {
                minSum = cur.sum;
            }

            for (int i = 0; i < 2; ++i) {
                int nx = cur.x + mov_x[i];
                int ny = cur.y + mov_y[i];
                if (validate_pos(grid, nx, ny)) {
                    q.push(Node(nx, ny, cur.sum + grid[nx][ny]));
                }
            }
        }

        return minSum;
    }
};
