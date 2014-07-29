class Solution:

    def __init__(self):
        self.operator = {
            '+': '__add__',
            '-': '__sub__',
            '*': '__mul__',
            '/': '__div__',
        }

    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stack = []
        for t in tokens:
            if t in ('+', '-', '*'):
                op2 = stack.pop()
                op1 = stack.pop()
                operator = getattr(op1, self.operator[t])
                stack.append(operator(op2))
            elif t == '/':
                op2 = stack.pop()
                op1 = stack.pop()
                operator = getattr(float(op1), self.operator[t])
                stack.append(int(operator(op2)))
            else:
                stack.append(int(t))
        return stack[0]

if __name__ == '__main__':
    s = Solution()
    assert s.evalRPN(['2', '1', '+', '3', '*']) == 9
    assert s.evalRPN(['0', '3', '/']) == 0
    assert s.evalRPN(["4", "13", "5", "/", "+"]) == 6
    assert s.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]) == 22
