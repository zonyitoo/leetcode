#include <string>
#include <tuple>
using namespace std;

class Solution {
public:
    int compareVersion(const string &version1, const string &version2) {
        auto itr1 = version1.begin();
        auto itr2 = version2.begin();
        while (itr1 != version1.end() && itr2 != version2.end()) {
            int code1 = 0, code2 = 0;
            while (itr1 != version1.end() && *itr1 != '.') {
                code1 = code1 * 10 + *itr1 - '0';
                ++itr1;
            }
            if (*itr1 == '.') ++itr1;

            while (itr2 != version2.end() && *itr2 != '.') {
                code2 = code2 * 10 + *itr2 - '0';
                ++itr2;
            }
            if (*itr2 == '.') ++itr2;

            if (code1 < code2) return -1;
            else if (code1 > code2) return 1;
        }

        if (itr1 == version1.end()) {
            while (itr2 != version2.end()) {
                int code2 = 0;
                while (itr2 != version2.end() && *itr2 != '.') {
                    code2 = code2 * 10 + *itr2 - '0';
                    ++itr2;
                }
                if (*itr2 == '.') ++itr2;
                if (code2 != 0) return -1;
            }
        } else if (itr2 == version2.end()) {
            while (itr1 != version1.end()) {
                int code1 = 0;
                while (itr1 != version1.end() && *itr1 != '.') {
                    code1 = code1 * 10 + *itr1 - '0';
                    ++itr1;
                }
                if (*itr1 == '.') ++itr1;
                if (code1 != 0) return 1;
            }
        }
        return 0;
    }
};
