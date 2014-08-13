class Solution:

    # @param num, a list of integer
    # @return a list of integer
    def nextPermutation(self, num):
        if len(num) <= 1:
            return num

        for idx in range(len(num) - 2, -1, -1):
            ii = idx + 1
            if num[idx] < num[ii]:
                j = len(num) - 1
                while not num[idx] < num[j]:
                    j -= 1
                num[idx], num[j] = num[j], num[idx]
                end = len(num) - 1
                while ii < end:
                    num[ii], num[end] = num[end], num[ii]
                    ii += 1
                    end -= 1
                return num
            if idx == 0:
                num.reverse()
                return num

if __name__ == '__main__':
    s = Solution()
    lst = [1]
    while True:
        print lst
        s.nextPermutation(lst)
