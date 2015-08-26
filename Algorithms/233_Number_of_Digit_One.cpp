class Solution {
public:
    int countDigitOne(int n) {
        int left = n, right = 0;
        int count = 0;
        int base = 1;

        /**
         *  For number `abc`
         *
         *  1. If `c` == 0, count += left * base, `left` is the number on the left of `c`
         *  2. If `c` == 1, count += (left * base + right + 1), `right` is the number on the right of `c`
         *  3. If `c` > 1, count += (left + 1) * base
         */
        while (left > 0) {
            int cur = left % 10;
            left /= 10;

            if (cur == 0) {
                count += left * base;
            } else if (cur == 1) {
                count += left * base + right + 1;
            } else {
                count += (left + 1) * base;
            }

            right += cur * base;
            base *= 10;
        }

        return count;
    }
};
