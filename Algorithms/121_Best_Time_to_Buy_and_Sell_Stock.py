class Solution:

    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if not prices:
            return 0
        ans = -0x7fffffff
        minimum = prices[0]
        for p in prices:
            ans = max((ans, p - minimum))
            minimum = min((minimum, p))
        return ans
