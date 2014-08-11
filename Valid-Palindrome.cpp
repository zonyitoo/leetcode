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

#include <cassert>
int main(int argc, char **argv) {
    Solution s;
    assert(s.isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(s.isPalindrome("race a car") == false);
    assert(s.isPalindrome(" ") == true);
    assert(s.isPalindrome("1a2") == false);
    return 0;
}
