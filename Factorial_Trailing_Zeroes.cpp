class Solution {
public:
    int trailingZeroes(int n) {
        int q = n;
        int zeros = 0;
        while (q != 0) {
            q /= 5;
            zeros += q;
        }
        return zeros;
    }
};
