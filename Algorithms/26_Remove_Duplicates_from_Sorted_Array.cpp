class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int ind = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[ind - 1]) {
                A[ind++] = A[i];
            }
        }

        return ind;
    }
};
