#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdint>
#include <cstring>
using std::vector;
using std::sort;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::min;

/*
 * LeetCode's judge system does not support bitset in STL.
 */
template <size_t N>
class bitset {
public:
    bitset()
        : cnt(0), data {0} {}

    void set(size_t offset) {
        int32_t setter = (1 << (offset % 32));
        if ((data[offset / 32] & setter) == 0) {
            ++cnt;
            data[offset / 32] |= setter;
        }
    }

    void reset(size_t offset) {
        int32_t setter = (1 << (offset % 32));
        if ((data[offset / 32] & setter) != 0) {
            --cnt;
            data[offset / 32] &= ~setter;
        }
    }

    size_t count() const {
        return cnt;
    }

    size_t size() const {
        return N;
    }

    bool operator[](size_t offset) const {
        return (data[offset / 32] & (1 << (offset % 32))) != 0;
    }

private:
    int32_t data[(N - 1) / 32 + 1];
    size_t cnt;
};

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        vector<bitset<9>> rowset(9), colset(9), sqset(9);
        vector<tuple<int, int>> plist;
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (board[row][col] == '.') {
                    plist.push_back(make_tuple(row, col));
                    continue;
                }
                int offset = board[row][col] - '1';
                rowset[row].set(offset);
                colset[col].set(offset);
                sqset[__square_index(row, col)].set(offset);
            }
        }

        sort(plist.begin(), plist.end(), [&](const tuple<int, int> &a, const tuple<int, int> &b) {
            int ra, ca, rb, cb;
            tie(ra, ca) = a;
            tie(rb, cb) = b;
            int availa = min(rowset[ra].size() - rowset[ra].count(),
                             min(colset[ca].size() - colset[ca].count(),
                                 sqset[__square_index(ra, ca)].size() - sqset[__square_index(ra, ca)].count()));
            int availb = min(rowset[rb].size() - rowset[rb].count(),
                             min(colset[cb].size() - colset[cb].count(),
                                 sqset[__square_index(rb, cb)].size() - sqset[__square_index(rb, cb)].count()));
            return availb < availa;
        });

        dfs_solve(board, plist, rowset, colset, sqset);
    }

private:
    bool dfs_solve(vector<vector<char>> &board, vector<tuple<int, int>> &plist,
                   vector<bitset<9>> &rowset,
                   vector<bitset<9>> &colset,
                   vector<bitset<9>> &sqset) {
        if (plist.empty()) {
            return true;
        }

        int row, col;
        tie(row, col) = plist.back();
        plist.pop_back();
        for (int n = 0; n < 9; ++n) {
            if (!rowset[row][n] && !colset[col][n] && !sqset[__square_index(row, col)][n]) {
                rowset[row].set(n);
                colset[col].set(n);
                sqset[__square_index(row, col)].set(n);
                board[row][col] = n + '1';
                if (dfs_solve(board, plist, rowset, colset, sqset)) {
                    return true;
                } else {
                    rowset[row].reset(n);
                    colset[col].reset(n);
                    sqset[__square_index(row, col)].reset(n);
                }
            }
        }
        plist.emplace_back(row, col);
        return false;
    }

    int __square_index(int x, int y) {
        return x / 3 * 3 + (y / 3);
    }
};
