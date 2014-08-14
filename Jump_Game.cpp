class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) {
            return true;
        }

        int max_jump = A[0];
        int cur = 1;
        while (cur < n && max_jump >= cur) {
            if (A[cur] + cur > max_jump) {
                max_jump = A[cur] + cur;
            }
            ++cur;
        }

        return (max_jump >= n - 1);
    }
};
