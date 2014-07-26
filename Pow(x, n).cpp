class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        double result = 1.0;
        while (n > 1 || n < -1) {
            if ((n & 1) == 1) {
                result *= x;
            }

            x *= x;
            n /= 2;
        }
        result *= x;

        if (n == -1) {
            result = 1.0 / result;
        }

        return result;
    }
};

#include <iostream>
using namespace std;

int main() {
    Solution s = Solution();
    cout << s.pow(10, -1) << endl;
    return 0;
}
