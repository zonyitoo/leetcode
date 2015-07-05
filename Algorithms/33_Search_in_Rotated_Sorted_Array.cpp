class Solution {
public:
    int search(int A[], int n, int target) {
        int begin = 0, end = n - 1;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > A[i + 1]) {
                begin = i + 1;
                end = i + n;
            }
        }

        while (begin <= end) {
            int origmid = (begin + end) / 2;
            int mid = origmid % n;
            if (A[mid] == target) {
                return mid;
            } else if (target < A[mid]) {
                end = origmid - 1;
            } else {
                begin = origmid + 1;
            }
        }

        return -1;
    }
};
