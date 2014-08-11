class Solution:

    # @return an integer
    def maxArea(self, height):
        if len(height) <= 1:
            return 0

        left, right = 0, len(height) - 1
        ret = 0
        while left < right:
            ret = max(ret, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return ret
