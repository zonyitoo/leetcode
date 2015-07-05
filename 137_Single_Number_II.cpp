class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i];   // Bits that appears two times
            ones ^= A[i];          // Add one or remove duplicates
            threes = ones & twos;  //
            ones &= ~threes;       // Remove bits that have appeared three times
            twos &= ~threes;
        }
        return ones;
    }
};
