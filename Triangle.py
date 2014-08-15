class Solution:

    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        if not triangle:
            return 0
        currow = triangle[-1]
        rowidx = len(triangle) - 2
        while rowidx >= 0:
            tmprow = [min((triangle[rowidx][idx] + currow[idx],
                          triangle[rowidx][idx] + currow[idx + 1]))
                      for idx in range(len(currow) - 1)]
            currow = tmprow
            rowidx -= 1
        return currow[0]
