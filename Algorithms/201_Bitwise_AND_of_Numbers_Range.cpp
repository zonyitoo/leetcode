#include <cstdio>

#include <cstdint>

class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;

        int lowerbound = nextPowerOfTwo(n) >> 1;

        if (lowerbound > m) return 0;
        else return lowerbound & n;
    }

  private:
    uint32_t nextPowerOfTwo(uint32_t x) {
        x--;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        x++;
        return x;
    }
};

int main() {
    int ret = Solution().rangeBitwiseAnd(6, 7);
    printf("%d\n", ret);
    return 0;
}
