class Solution:

    # @return an integer
    def threeSumClosest(self, num, target):
        if len(num) <= 2:
            return 0

        num.sort()
        ans = num[0] + num[1] + num[2]
        for idx, n in enumerate(num[:-2]):
            left = idx + 1
            right = len(num) - 1
            while left < right:
                tmp = n + num[left] + num[right]
                if abs(tmp - target) < abs(ans - target):
                    ans = tmp
                    if tmp == target:
                        return ans
                if tmp < target:
                    left += 1
                else:
                    right -= 1

        return ans
