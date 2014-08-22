#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string longestPalindrome(const string &s) {
        if (s.empty()) {
            return s;
        }
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int bak = 0; bak <= 1; ++bak) {
                int ml = i - bak, mr = i + 1, len = bak;
                bool is_palin = true;
                while (ml >= 0 && mr < s.size()) {
                    if (s[ml] != s[mr]) {
                        if (len > maxlength) {
                            left = ml + 1;
                            right = mr - 1;
                            maxlength = len;
                        }
                        is_palin = false;
                        break;
                    }
                    len += 2;
                    --ml, ++mr;
                }

                if (is_palin && len > maxlength) {
                    left = ml + 1;
                    right = mr - 1;
                    maxlength = len;
                }
            }
        }

        return s.substr(left, right - left + 1);
    }
};
