#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(const string &s) {
        int number = 0;
        for (auto c : s) {
            number = number * 26 + c - 'A' + 1;
        }

        return number;
    }
};
