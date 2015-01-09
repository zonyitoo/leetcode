class Solution {
private:
    class Iter {
        const int *A;
        int m;
        const int *B;
        int n;

        int idxa, idxb;

    public:
        Iter(const int *A, int m, const int *B, int n)
            : A(A), m(m), B(B), n(n), idxa(0), idxb(0) {}

        bool hasNext() const {
            return idxa == m && idxb == n;
        }

        int next() {
            if (idxa != m && idxb != n) {
                int res;
                if (A[idxa] < B[idxb]) res = A[idxa++];
                else res = B[idxb++];
                return res;
            } else if (idxa == m) {
                return B[idxb++];
            } else {
                return A[idxa++];
            }
        }
    };


public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int target_pos = (m + n - 1) / 2;
        int cur_num;

        Iter iter(A, m, B, n);
        while (target_pos-- >= 0) cur_num = iter.next();

        if (((m + n) & 1) == 0) {
            int one_more = iter.next();
            return (cur_num + one_more) / 2.0;
        } else {
            return cur_num;
        }
    }
};
