class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0)
            return 0;
        int max = A[0];
        int sum = 0;
        for (int i = 0; i < n; ++ i) {
            if (sum >= 0) {
                sum += A[i];
            } else {
                sum = A[i];
            }

            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};
