class Solution {
public:
    bool search(int A[], int n, int target) {
        int beg = 0, end = n - 1;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > A[i + 1]) {
                beg = i + 1;
                end = i + n;
                break;
            }
        }

        while (beg <= end) {
            int origmid = (beg + end) / 2;
            int realmid = origmid % n;
            if (A[realmid] == target) {
                return true;
            } else if (target < A[realmid]) {
                end = origmid - 1;
            } else {
                beg = origmid + 1;
            }
        }

        return false;
    }
};
