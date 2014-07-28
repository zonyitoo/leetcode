#include <climits>
#include <cassert>

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

int main() {
    Solution s;

    assert(s.atoi("12345") == 12345);
    assert(s.atoi("-12345") == -12345);
    assert(s.atoi("   12345") == 12345);
    assert(s.atoi("abcddd12345") == 0);
    assert(s.atoi("123456abcdefg") == 123456);
    assert(s.atoi("-") == 0);
    assert(s.atoi("2147483648") == INT_MAX);
    assert(s.atoi("-2147483649") == INT_MIN);
    assert(s.atoi("+1") == 1);
    assert(s.atoi("    10522545459") == INT_MAX);

    return 0;
}
