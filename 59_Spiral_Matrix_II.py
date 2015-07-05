class Solution:

    # @return a list of lists of integer
    def generateMatrix(self, n):
        result = [[0 for _ in range(n)] for _ in range(n)]
        self.__solve(result, 1, (0, n), (0, n))
        return result

    def __solve(self, result, num, xlimit, ylimit):
        if xlimit[0] >= xlimit[1] or ylimit[0] >= ylimit[1]:
            return

        for y in range(*ylimit):
            result[xlimit[0]][y] = num
            num += 1
        for x in range(xlimit[0] + 1, xlimit[1]):
            result[x][ylimit[1] - 1] = num
            num += 1
        for y in range(ylimit[1] - 2, ylimit[0] - 1, -1):
            result[xlimit[1] - 1][y] = num
            num += 1
        for x in range(xlimit[1] - 2, xlimit[0], -1):
            result[x][ylimit[0]] = num
            num += 1

        self.__solve(result, num, (xlimit[0] + 1, xlimit[1] - 1), (ylimit[0] + 1, ylimit[1] - 1))
