class Solution:

    def __init__(self):
        self.digit_chars = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
            '0': ' ',
        }

    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        if not digits:
            return [""]
        result = []
        chars = self.digit_chars[digits[0]]
        rest_parts = self.letterCombinations(digits[1:])
        for c in chars:
            for rp in rest_parts:
                result.append(c + rp)
        return result
