#include <cstddef>

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const char *begin = s;
        ptrdiff_t cnt = 0;
        while (*s != '\0') {
            if (*s == ' ') {
                if (s != begin) {
                    cnt = s - begin;
                }
                begin = s + 1;
            }
            ++s;
        }
        if (s != begin) {
            cnt = s - begin;
        }

        return cnt;
    }
};
