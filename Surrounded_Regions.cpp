#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <queue>
using std::queue;
#include <tuple>
using std::tie;
using std::make_tuple;
using std::tuple;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) {
            return;
        }

        int max_x = board.size(), max_y = board[0].size();

        vector<vector<bool>> visited(max_x,
                                     vector<bool>(max_y, false));

        static const int mv_x[] = {0, 1, 0, -1};
        static const int mv_y[] = {1, 0, -1, 0};

        bool found = false;
        while (true) {
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[i].size(); ++j) {
                    if (board[i][j] == 'O' && !visited[i][j]) {
                        found = true;
                        queue<tuple<int, int>> q;
                        visited[i][j] = true;
                        q.push(make_tuple(i, j));
                        bool is_valid = true;
                        while (!q.empty()) {
                            int x, y;
                            tie(x, y) = q.front();
                            q.pop();

                            for (int i = 0; i < 4; ++i) {
                                int nx = x + mv_x[i];
                                int ny = y + mv_y[i];
                                if (nx >= 0 && nx < max_x && ny >= 0 && ny < max_y) {
                                    if (board[nx][ny] == 'O' && !visited[nx][ny]) {
                                        visited[nx][ny] = true;
                                        q.push(make_tuple(nx, ny));
                                    }
                                } else {
                                    is_valid = false;
                                }
                            }
                        }

                        if (is_valid) {
                            while (!q.empty())
                                q.pop();
                            q.push(make_tuple(i, j));
                            while (!q.empty()) {
                                int x, y;
                                tie(x, y) = q.front();
                                q.pop();

                                board[x][y] = 'X';

                                for (int i = 0; i < 2; ++i) {
                                    int nx = x + mv_x[i];
                                    int ny = y + mv_y[i];
                                    if (nx >= 0 && nx < max_x && ny >= 0 && ny < max_y) {
                                        if (board[nx][ny] == 'O') {
                                            q.push(make_tuple(nx, ny));
                                        }
                                    }
                                }
                            }
                        }
                    }
                    found = false;
                }
            }
            if (!found) break;
        }
    }
};

int main(int argc, char **argv) {
    {
        char matrix[4][4] = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
        };

        vector<vector<char>> vec;
        for (int i = 0; i < 4; ++i) {
            vector<char> tmp;
            for (int j = 0; j < 4; ++j) {
                tmp.push_back(matrix[i][j]);
            }
            vec.push_back(tmp);
        }

        Solution s;
        s.solve(vec);

        for (auto &row : vec) {
            for (auto &col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
