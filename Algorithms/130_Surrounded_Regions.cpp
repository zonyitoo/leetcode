#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) const {
        if (board.size() == 0) return;

        vector<vector<bool>> safe(board.size(), vector<bool>(board[0].size(), false));

        int xrange[] = {0, (int) board.size() - 1};
        int yrange[] = {0, (int) board[0].size() - 1};
        for (auto &x : xrange) {
            for (int y = 0; y < board[x].size(); ++y) {
                markSafe(board, safe, x, y);
            }
        }

        for (auto &y : yrange) {
            for (int x = 0; x < board.size(); ++x) {
                markSafe(board, safe, x, y);
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O' && !safe[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    inline void markSafe(vector<vector<char>> &board, vector<vector<bool>> &safe,
                         int begx, int begy) const {
        if (board[begx][begy] != 'O' || safe[begx][begy]) return;

        queue<pair<int, int>> q;
        safe[begx][begy] = true;
        q.push(make_pair(begx, begy));
        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            const int mv_x[] = {1, -1, 0, 0};
            const int mv_y[] = {0, 0, 1, -1};

            for (int i = 0; i < 4; ++i) {
                int nx = front.first + mv_x[i];
                int ny = front.second + mv_y[i];
                if (validPos(board, nx, ny) && board[nx][ny] == 'O' && !safe[nx][ny]) {
                    safe[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    inline bool validPos(const vector<vector<char>> &board, int x, int y) const {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
};


#include <iostream>
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
