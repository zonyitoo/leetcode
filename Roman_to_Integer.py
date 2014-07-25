class Solution:

    def __init__(self):
        self.roman_to_int = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }

    # @return an integer
    def romanToInt(self, s):
        upper_str = s.upper()
        result = 0
        ind = 0
        while ind < len(upper_str):
            cur_num = self.roman_to_int[upper_str[ind]]
            nxt_num = self.roman_to_int[upper_str[ind + 1]] if ind != len(upper_str) - 1 else None
            if cur_num in (1, 10, 100) and nxt_num is not None and nxt_num > cur_num:
                result += nxt_num - cur_num
                ind += 2
            else:
                result += cur_num
                ind += 1
        return result
