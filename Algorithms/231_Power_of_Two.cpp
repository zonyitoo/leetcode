#include <limits>

class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n == 0 || n == std::numeric_limits<int>::min()) return false;
        return (n & (n - 1)) == 0;
    }
};
