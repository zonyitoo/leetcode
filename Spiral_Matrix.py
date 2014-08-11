class Solution:

    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        result = []
        if matrix:
            self.__solve(result, matrix, (0, len(matrix)), (0, len(matrix[0])))
        return result

    def __solve(self, result, matrix, xlimit, ylimit):
        if xlimit[0] >= xlimit[1] or ylimit[0] >= ylimit[1]:
            return

        for y in range(*ylimit):
            result.append(matrix[xlimit[0]][y])
        for x in range(xlimit[0] + 1, xlimit[1]):
            result.append(matrix[x][ylimit[1] - 1])
        if xlimit[1] - xlimit[0] > 1:
            for y in range(ylimit[1] - 2, ylimit[0] - 1, -1):
                result.append(matrix[xlimit[1] - 1][y])
        if ylimit[1] - ylimit[0] > 1:
            for x in range(xlimit[1] - 2, xlimit[0], -1):
                result.append(matrix[x][ylimit[0]])

        self.__solve(result, matrix, (xlimit[0] + 1, xlimit[1] - 1), (ylimit[0] + 1, ylimit[1] - 1))

if __name__ == '__main__':
    s = Solution()
    order = s.spiralOrder([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
    ])
    print(order)
    order = s.spiralOrder([
        [2],
        [3],
    ])
    print(order)
    order = s.spiralOrder([
        [6, 9, 7],
    ])
    print(order)
