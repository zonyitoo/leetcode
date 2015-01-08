class Solution:

    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        if not s:
            return []
        ans = [[s[0]]]
        for c in s[1:]:
            tmp = [a + [c] for a in ans]
            news = []
            idx = len(ans[0]) - 1
            while idx >= 0:
                tmps = ''.join(ans[0][idx:]) + c
                if self.is_palindrome(tmps):
                    news.append(ans[:idx] + [tmps])
                idx -= 1
            ans = tmp + news
        return ans

    def is_palindrome(self, string):
        left, right = 0, len(string) - 1
        while left <= right:
            if string[left] != string[right]:
                return False
            left += 1
            right -= 1
        return True


if __name__ == '__main__':
    s = Solution()
    print s.partition('eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj')
