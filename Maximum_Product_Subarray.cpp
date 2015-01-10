#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) return 0;

        long long prev_max = A[0], prev_min = A[0];
        long long max_prod = A[0];
        for (int i = 1; i < n; ++i) {
            long long prot_0 = A[i] * prev_max, prot_1 = A[i] * prev_min;
            prev_max = max(prot_0, max(prot_1, static_cast<long long>(A[i])));
            prev_min = min(prot_0, min(prot_1, static_cast<long long>(A[i])));

            max_prod = max(prev_max, max_prod);
        }

        return max_prod;
    }
};
