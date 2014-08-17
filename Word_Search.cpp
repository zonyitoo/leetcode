#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    bool exist(const vector<vector<char>> &board, const string &word) {
        if (board.empty() || word.empty()) {
            return false;
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[r].size(); ++c) {
                visited[r][c] = true;
                if (__solve(board, r, c, visited, word.cbegin(), word.cend())) {
                    return true;
                }
                visited[r][c] = false;
            }
        }
        return false;
    }

private:
    bool __solve(const vector<vector<char>> &board, int r, int c, vector<vector<bool>> &visited,
                 string::const_iterator itr, string::const_iterator end) {
        if (board[r][c] != *itr) {
            return false;
        }

        ++itr;
        if (itr == end) {
            return true;
        }

        static const int mv_r[] = {0, 0, -1, 1};
        static const int mv_c[] = { -1, 1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            int nr = r + mv_r[i];
            int nc = c + mv_c[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[nr].size() && !visited[nr][nc]) {
                visited[nr][nc] = true;
                if (__solve(board, nr, nc, visited, itr, end)) {
                    return true;
                }
                visited[nr][nc] = false;
            }
        }
        return false;
    }
};
