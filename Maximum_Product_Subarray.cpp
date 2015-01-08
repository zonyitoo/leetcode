#include <algorithm>

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) {
            return 0;
        }

        long long prod = A[0];
        long long maximum = A[0];

        for (int i = 1; i < n; ++i) {
            if (A[i] == A[i - 1] + 1 || A[i] == A[i - 1]) {
                prod *= A[i];
            } else {
                maximum = std::max(maximum, prod);

                prod = A[i];
            }
        }

        maximum = std::max(maximum, prod);

        return maximum;
    }
};

#include <cstdio>

int main() {
    Solution s;

    int arr[] = { -4, -3, -2};

    printf("%d\n", s.maxProduct(arr, 4));

    return 0;
}
