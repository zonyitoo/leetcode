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
