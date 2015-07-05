#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        bool carry = 0;

        string::reverse_iterator itra = a.rbegin(), itrb = b.rbegin();
        while (itra != a.rend() || itrb != b.rend()) {
            char sum = 0;
            if (carry) {
                carry = false;
                sum += 1;
            }
            if (itra != a.rend()) {
                sum += (*itra) - '0';
                ++itra;
            }
            if (itrb != b.rend()) {
                sum += (*itrb) - '0';
                ++itrb;
            }
            if (sum >= 2) {
                carry = true;
                sum -= 2;
            }
            result.push_back(sum + '0');
        }

        if (carry) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
