#include <vector>
#include <climits>

class Solution {
public:
    int jump(int A[], int n) {
        std::vector<int> can(n, -1);
        dfs_solve(can, A, 0);
        return can[0];
    }

private:
    int dfs_solve(std::vector<int> &can, int A[], int idx) {
        if (can[idx] != -1) {
            return can[idx];
        }

        if (idx == can.size() - 1) {
            can[idx] = 0;
            return 0;
        } else if (can[idx] == INT_MAX) {
            return INT_MAX;
        }

        if (can.size() - idx <= A[idx]) {
            can[idx] = 1;
            return 1;
        }

        int mini = INT_MAX;
        for (int i = A[idx]; i >= 1 && idx + i < can.size(); --i) {
            int _st = dfs_solve(can, A, idx + i);
            if (_st < mini) {
                mini = _st;
            }
            if (mini <= 1) {
                break;
            }
        }
        if (mini == INT_MAX) {
            return INT_MAX;
        }

        can[idx] = mini + 1;
        return can[idx];
    }
};

