class Solution {
public:
    void insert(int A[], int m, int pos, int elem) {
        for (int i = m; i > pos; --i) {
            A[i] = A[i - 1];
        }
        A[pos] = elem;
    }

    void merge(int A[], int m, int B[], int n) {
        int mind = 0;
        int inda = 0, indb = 0;

        while (inda < m && indb < n) {
            if (A[inda] <= B[indb]) {
                if (mind == inda) {
                    insert(A, m++, mind++, A[inda++]);
                    inda++;
                } else {
                    A[mind++] = A[inda++];
                }
            } else {
                if (mind == inda) {
                    insert(A, m++, mind++, B[indb++]);
                    inda++;
                } else {
                    A[mind++] = B[indb++];
                }
            }
        }

        if (inda < m && inda != mind + 1) {
            while (inda < m) {
                A[mind++] = A[inda++];
            }
        } else if (indb < n) {
            while (indb < n) {
                A[mind++] = B[indb++];
            }
        }
    }
};
