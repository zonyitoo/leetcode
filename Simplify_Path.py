class Solution:

    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        paths = path.split('/')
        stack = []
        for p in paths:
            if p == '..':
                if stack:
                    stack.pop()
            elif p == '.':
                pass
            elif p:
                stack.append(p)
        return '/' + '/'.join(stack)


if __name__ == '__main__':
    s = Solution()
    assert s.simplifyPath('/home/') == '/home'
    assert s.simplifyPath('/a/./b/../../c/') == '/c'
    assert s.simplifyPath('/../c/') == '/c'
    assert s.simplifyPath('/.') == '/'
    assert s.simplifyPath('/..') == '/'
