class Solution:

    # @return an integer
    def totalNQueens(self, n):
        return sum(self.dfs((1 << n) - 1, 0, 0, 0))

    def dfs(self, fullrow, currow, lcross, rcross):
        if currow == fullrow:
            yield 1
            return
        remain = fullrow & (~(currow | lcross | rcross))
        while remain != 0:
            pos = remain & (-remain)
            remain -= pos
            for i in self.dfs(fullrow, currow + pos, (lcross + pos) << 1, (rcross + pos) >> 1):
                yield i
