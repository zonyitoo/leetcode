class Solution:

    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if not prices:
            return 0
        ans = 0
        for idx, p in enumerate(prices):
            if idx != 0:
                if (p > prices[idx - 1]):
                    ans += p - prices[idx - 1]
        return ans
