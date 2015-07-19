/**
 * # The Idea
 *
 * The result is the same bits of `m` and `n`.
 *
 * ## Analysis
 *
 * A number `n` plus 1, it will makes the lower bits of this number to change from 0 to 1 or from 1 to 0.
 * For example, 5 (101) plus 1 to become 6 (110), the last two bits change, 6 (110) plus 1 to become 7 (111),
 * the last one bit changes.
 *
 * For 6 to 9,
 * ```
 * 6 (0110)
 * 7 (0111)
 * 8 (1000)
 * 9 (1001)
 * ```
 *
 * The answer is `1000`.
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = 0xffffffff;

        while (m != 0) {
            if ((m & mask) == (n & mask)) {
                break;
            }
            mask <<= 1;
        }

        return m & mask;
    }
};
