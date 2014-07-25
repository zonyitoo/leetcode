class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for (int i = 0; i < n; i++) {
            if (A[i] == elem) {
                while (i < n && A[n - 1] == elem) {
                    n--;
                }
                if (i == n) break;
                A[i] = A[n - 1];
                n--;
            }
        }
        return n;
    }
};
