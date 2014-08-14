#include <climits>

class Solution {
public:
    int atoi(const char *str) {
        long long result = 0;
        while (*str != '\0' && *str == ' ')
            ++str;
        bool minus = false;
        if (*str == '-') {
            ++str;
            minus = true;
        } else if (*str == '+') {
            ++str;
        }
        if (*str == '\0' || !(*str >= '0' && *str <= '9')) {
            return 0;
        }
        while (*str != '\0' && *str >= '0' && *str <= '9') {
            result *= 10;
            if (minus) {
                result -= *str - '0';
                if (result < INT_MIN)
                    return INT_MIN;
            }
            else {
                result += *str - '0';
                if (result > INT_MAX)
                    return INT_MAX;
            }

            ++str;
        }
        return result;
    }
};

