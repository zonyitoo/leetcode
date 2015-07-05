#include <utility>

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Bucket sort
        for (int i = 0; i < n; ++i) {
            int tmp = A[i];
            while (tmp > 0 && tmp <= n && tmp != A[tmp - 1]) {
                std::swap(tmp, A[tmp - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n == 0 ? 1 : A[n - 1] + 1;
    }
};
