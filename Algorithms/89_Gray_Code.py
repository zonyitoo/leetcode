class Solution:

    # @return a list of integers
    def grayCode(self, n):
        result = [0, ]
        for pos in range(n):
            tmp = [item for item in result]
            tmp += [(result[idx] | (1 << pos)) for idx in range(len(result) - 1, -1, -1)]
            result = tmp
        return result
