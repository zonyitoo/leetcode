class Solution:

    def divide(self, dividend, divisor):
        '''
        Divide two integers without using multiplication, division and mod operator.

        :param dividend: Dividend
        :type dividend: int
        :param divisor: Divisor
        :type divisor: int
        :return: Quotient
        :rtype: int

        '''
        is_minor = False
        if dividend < 0:
            is_minor ^= True
            dividend = -dividend
        if divisor < 0:
            is_minor ^= True
            divisor = -divisor
        cnt = 0
        while dividend >= divisor:
            tmpdiv = divisor
            tmpcnt = 1
            while tmpdiv + tmpdiv <= dividend:
                tmpdiv += tmpdiv
                tmpcnt += tmpcnt
            cnt += tmpcnt
            dividend -= tmpdiv
        return cnt if not is_minor else -cnt
