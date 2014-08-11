#include <vector>
using std::vector;

class Solution {
public:
    bool isValidSudoku(const vector<vector<char>> &board) {
        vector<int> validrow(9), validcol(9);
        vector<int> validsq(9);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if ((validrow[i] & (1 << num)) != 0
                        || (validcol[j] & (1 << num)) != 0
                        || (validsq[__square_index(i, j)] & (1 << num)) != 0) {
                    return false;
                }

                validrow[i] |= (1 << num);
                validcol[j] |= (1 << num);
                validsq[__square_index(i, j)] |= (1 << num);
            }
        }
        return true;
    }

private:
    int __square_index(int x, int y) {
        return x / 3 * 3 + (y / 3);
    }
};

#include <cassert>

int main() {
    vector<vector<char>> board = {
        {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
        {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
        {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
        {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    Solution s;
    assert(s.isValidSudoku(board) == false);
    return 0;
}
