class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0' && *p == '\0') {
            return true;
        }

        if (*s == '\0' && *p != '\0') {
            if (*(p + 1) == '*') {
                return isMatch(s, p + 2);
            }
            return false;
        } else if (*p == '\0') {
            return false;
        }

        if (*(p + 1) == '*') {
            if (*p != *s && *p != '.') {
                return isMatch(s, p + 2);
            }

            while (*p != '\0' && *(p + 1) == '*') {
                if (*p == *s || *p == '.') {
                    if (isMatch(s + 1, p)) {
                        return true;
                    }
                }

                p += 2;
            }

            return isMatch(s, p);
        } else {
            if (*s != *p && *p != '.') {
                return false;
            }

            return isMatch(s + 1, p + 1);
        }
    }
};
