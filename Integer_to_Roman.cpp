#include <string>
using std::string;

class Solution {
public:

    struct RomanInt {
        char roman;
        int integer;
    };

    string intToRoman(int num) {
        string result;

        static const RomanInt roman_to_int[7] = {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
        };

        int b_ind = 0;

        int n = num / roman_to_int[b_ind].integer;
        num %= roman_to_int[b_ind].integer;
        result.append(n, roman_to_int[b_ind].roman);

        b_ind++;

        while (num != 0) {
            n = num / roman_to_int[b_ind + 1].integer;
            num %= roman_to_int[b_ind + 1].integer;

            if (n == 9) {
                result.push_back(roman_to_int[b_ind + 1].roman);
                result.push_back(roman_to_int[b_ind - 1].roman);
            } else if (n >= 5) {
                result.push_back(roman_to_int[b_ind].roman);
                result.append(n - 5, roman_to_int[b_ind + 1].roman);
            } else if (n == 4) {
                result.push_back(roman_to_int[b_ind + 1].roman);
                result.push_back(roman_to_int[b_ind].roman);
            } else {
                result.append(n, roman_to_int[b_ind + 1].roman);
            }

            b_ind += 2;
        }

        return result;
    }
};
