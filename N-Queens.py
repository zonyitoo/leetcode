class Solution:

    # @return a list of lists of string
    def solveNQueens(self, n):
        return list(self.dfs((1 << n) - 1, 0, 0, 0, []))

    def dfs(self, fullrow, currow, lcross, rcross, ans):
        if currow == fullrow:
            yield ans[:]
            return
        remain = fullrow & (~(currow | lcross | rcross))
        while remain != 0:
            pos = remain & (-remain)
            remain -= pos

            tmppos = pos
            tmpfullrow = fullrow
            tmpstr = ''
            while tmpfullrow != 0:
                tmpstr += '.' if tmppos & 1 == 0 else 'Q'
                tmppos >>= 1
                tmpfullrow >>= 1
            ans.append(tmpstr)

            for i in self.dfs(fullrow, currow + pos, (lcross + pos) << 1, (rcross + pos) >> 1, ans):
                yield i

            ans.pop()
