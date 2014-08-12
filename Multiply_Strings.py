class Solution:

    # @param num1, a string
    # @param num2, a string
    # @return a string
    def multiply(self, num1, num2):
        pre = []
        for idx2 in range(len(num2) - 1, -1, -1):
            carry = 0
            cur = [0] * (len(num2) - 1 - idx2)
            for idx1 in range(len(num1) - 1, -1, -1):
                r = 0
                if carry != 0:
                    r += carry
                    carry = 0
                r += int(num2[idx2]) * int(num1[idx1])
                if r >= 10:
                    carry = r / 10
                    r %= 10
                cur.append(r)
            if carry != 0:
                cur.append(carry)

            while len(cur) > 1 and cur[-1] == 0:
                cur.pop()

            pre = self.add(pre, cur)

        pre.reverse()
        return ''.join(map(str, pre))

    def add(self, arr1, arr2):
        result = []
        carry = False
        idx = 0
        while idx < len(arr1) or idx < len(arr2):
            r = 0
            if carry:
                r += 1
                carry = False
            if idx < len(arr1):
                r += arr1[idx]
            if idx < len(arr2):
                r += arr2[idx]
            if r >= 10:
                carry = True
                r -= 10
            result.append(r)
            idx += 1
        if carry:
            result.append(1)
        return result


if __name__ == '__main__':
    s = Solution()
    print(s.multiply('00001', '20') == str(1 * 20))
    print(s.multiply('123456', '435325324523523452345') == str(123456 * 435325324523523452345))
    print(s.multiply('9369162965141127216164882458728854782080715827760307787224298083754', '7204554941577564438')
          == str(9369162965141127216164882458728854782080715827760307787224298083754 * 7204554941577564438))
