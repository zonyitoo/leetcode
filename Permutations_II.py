class Solution:

    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, num):
        visited = [False for _ in num]
        num.sort()
        return self.__solve(visited, num)

    def __solve(self, visited, num):
        result = []
        if all(visited):
            return result

        last = None
        for idx, n in enumerate(num):
            if visited[idx] is False and n != last:
                visited[idx] = True
                subres = self.__solve(visited, num)
                if subres:
                    for sr in subres:
                        result.append([n] + sr)
                else:
                    result.append([n])
                visited[idx] = False
                last = n
        return result


if __name__ == '__main__':
    s = Solution()
    print s.permuteUnique([1, 1, 1, 1, 1, 2])
