class Solution:

    # @return a boolean
    def isValid(self, s):
        stack = []
        for c in s:
            if c in '{[(':
                stack.append(c)
            else:
                try:
                    top = stack[-1]
                    if c == '}' and top == '{':
                        stack.pop()
                    elif c == ']' and top == '[':
                        stack.pop()
                    elif c == ')' and top == '(':
                        stack.pop()
                    else:
                        return False
                except IndexError:
                    return False

        return len(stack) == 0
