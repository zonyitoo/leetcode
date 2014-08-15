class Solution:

    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n < 0:
            return 1.0 / self.pow(x, -n)
        elif n == 0:
            return 1.0

        result = 1.0
        while n > 1:
            if n & 1 == 1:
                result *= x
            x = x * x
            n = n // 2
        else:
            result *= x
        return result
