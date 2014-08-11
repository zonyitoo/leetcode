class Solution {
public:
    void sortColors(int A[], int n) {
        int zero = 0, mover = 0, two = n - 1;
        while (mover <= two) {
            if (A[mover] == 0) {
                A[mover] = A[zero];
                A[zero++] = 0;
                if (zero > mover) {
                    ++mover;
                }
            } else if (A[mover] == 2) {
                A[mover] = A[two];
                A[two--] = 2;
            } else {
                ++mover;
            }
        }
    }
};
