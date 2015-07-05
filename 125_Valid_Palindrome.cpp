#include <string>
using std::string;
#include <cstring>
using std::tolower;
using std::isalnum;

class Solution {
public:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < s.size() && !isalnum(s[l])) ++l;
            while (r >= 0 && !isalnum(s[r])) --r;
            if (l > r) break;
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            --r;
            ++l;
        }

        return true;
    }
};
