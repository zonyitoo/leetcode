#include "leetcode.hpp"

#include <algorithm>

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        if (board.empty())
            return;

        vector<int> prev_line(board[0].size());
        vector<int> cur_line(board[0].size());
        for (size_t x = 0; x < board.size(); ++x) {
            for (size_t y = 0; y < board[x].size(); ++y) {
                cur_line[y] = this->interact(board, x, y);
            }

            if (x != 0) {
                std::swap(board[x - 1], prev_line);
            }
            std::swap(prev_line, cur_line);
        }
        std::swap(board.back(), prev_line);
    }

private:
    int interact(vector<vector<int>> const &board, size_t x, size_t y) const {
        const static long mv_x[] = {0, 0, -1, 1, -1, -1, 1, 1};
        const static long mv_y[] = {-1, 1, 0, 0, -1, 1, -1, 1};

        const auto is_valid = [&board](long x, long y) {
            return x >= 0 && x < static_cast<long>(board.size()) && y >= 0 && y < static_cast<long>(board[0].size());
        };

        int lives = 0, dies = 0;
        for (size_t i = 0; i < 8; ++i) {
            const long nx = x + mv_x[i];
            const long ny = y + mv_y[i];

            if (is_valid(nx, ny)) {
                if (board[nx][ny] == 0) {
                    ++dies;
                } else {
                    ++lives;
                }
            }
        }

        if (board[x][y] == 1) {
            if (lives < 2 || lives > 3) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (lives == 3) {
                return 1;
            } else {
                return 0;
            }
        }
    }
};
