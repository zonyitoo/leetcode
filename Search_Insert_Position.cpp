class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0) return 0;
        return binarySearch(A, 0, n - 1, target);
    }

    int binarySearch(int A[], int beg, int end, int target) {
        while (beg != end) {
            int mid = (beg + end) / 2;
            if (target == A[mid]) {
                return mid;
            }
            if (target < A[mid]) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }

        if (target == A[beg]) {
            return beg;
        } else {
            return (target < A[beg]) ? beg : beg + 1;
        }
    }
};
