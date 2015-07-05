#include <vector>
#include <cmath>
using std::vector;

class Solution {
  public:
    int countPrimes(int n) {
        if (n <= 1) return 0;

        vector<int> is_prime(n, true);

        is_prime[0] = is_prime[1] = false;

        for (int i = 4; i < n; i += 2) {
            is_prime[i] = false;
        }

        for (int i = 3; i < n; i += 2) {
            if (is_prime[i]) {
                int sqrt_i = sqrt(i);
                for (int j = 2; j < sqrt_i; ++j) {
                    if (is_prime[j] && i % j == 0) {
                        is_prime[i] = false;
                        break;
                    }
                }

                for (int j = 2; i * j < n; ++j) {
                    is_prime[i * j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (is_prime[i]) count++;
        }

        return count;
    }
};


int main() {
    int ret = Solution().countPrimes(1500000);
    printf("%d\n", ret);
    return 0;
}
