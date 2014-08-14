#include <cmath>

class Solution {
public:
    int sqrt(int x) {
        // Newton-Raphson method
#define PRECISION 1e-3

        double result = 1.0;
        while (true) {
            double tmp = result - (result * result - x) / (2 * result);
            if (std::fabs(tmp - result) < PRECISION) {
                result = tmp;
                break;
            }
            result = tmp;
        }

        return result;
    }
};

