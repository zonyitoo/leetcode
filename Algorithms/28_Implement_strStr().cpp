#include <cstring>
using std::strlen;

class Solution {
public:
    const char *strStr(const char *haystack, const char *needle) {
        int pos = sunday(haystack, needle);
        return (pos == -1) ? nullptr : haystack + pos;
    }

private:
    int sunday(const char *src, const char *dst) {
        int slen = strlen(src);
        int dlen = strlen(dst);

        int next[256];
        for (int i = 0; i < 256; ++i) {
            next[i] = dlen + 1;
        }
        for (int i = 0; i < dlen; ++i) {
            next[dst[i]] = dlen - i;
        }

        int pos = 0;
        while (pos < (slen - dlen) + 1) {
            bool found = true;
            for (int i = pos, j = 0; j < dlen; ++j, ++i) {
                if (src[i] != dst[j]) {
                    pos += next[src[pos + dlen]];
                    found = false;
                    break;
                }
            }
            if (found) {
                return pos;
            }
        }
        return -1;
    }
};
