#include <algorithm>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream sstream;
        long r = static_cast<long>(numerator) / denominator;
        if (r == 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))) {
            sstream << "-";
        }
        long n_numerator = static_cast<long>(numerator) % denominator;
        sstream << r;

        if (n_numerator != 0) {
            sstream << '.';

            stringstream fraction;
            map<int, int> numers;
            int repeat = -1;
            for (int i = 0; ; ++i) {
                n_numerator *= 10;
                auto itr = numers.find(n_numerator);
                if (itr != numers.end()) {
                    repeat = itr->second;
                    break;
                }

                numers[n_numerator] = i;
                int r = n_numerator / denominator;
                fraction << fabs(r);
                n_numerator %= denominator;

                if (n_numerator == 0) break;
            }

            if (repeat != -1) {
                while (repeat--) {
                    char c;
                    fraction >> c;
                    sstream << c;
                }
                sstream << "(";
                char c;
                while (fraction >> c) {
                    sstream << c;
                }
                sstream << ")";
            } else {
                sstream << fraction.str();
            }
        }

        return sstream.str();
    }
};
