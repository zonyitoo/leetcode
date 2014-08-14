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
