class Solution:

    # @return a boolean
    def isPalindrome(self, x):
        if x < 0:
            return False

        leftdiv = 1
        while x // leftdiv >= 10:
            leftdiv *= 10
        while x != 0:
            if x // leftdiv != x % 10:
                return False
            x = (x % leftdiv) // 10
            leftdiv //= 100
        return True

if __name__ == '__main__':
    s = Solution()
    assert s.isPalindrome(12321) is True
    assert s.isPalindrome(111111111111111111111111111111111111111111) is True
