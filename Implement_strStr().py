class Solution:

    def strStr(self, haystack, needle):
        '''
        Find a substring (needle) in haystack.

        :param haystack: haystack
        :type haystack: str
        :param needle: needle
        :type needle: str
        :return: a string or None

        Usage:
            >>> s = Solution()
            >>> s.strStr("example hello", "example")

        '''
        pos = self.sunday(haystack, needle)
        return haystack[pos:] if pos != -1 else None

    def sunday(self, src, dst):
        next = {c: len(dst) - idx for idx, c in enumerate(dst)}
        pos = 0
        while pos < len(src) - len(dst) + 1:
            for idx, c in enumerate(dst):
                if c != src[pos + idx]:
                    if pos + len(dst) >= len(src):
                        return -1
                    jump_c = src[pos + len(dst)]
                    pos += len(dst) + 1 if jump_c not in next else next[jump_c]
                    break
            else:
                return pos
        return -1
