class Solution:

    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        if not candidates:
            return []
        candidates.sort()
        ans = []
        result = [(0, [])]
        if candidates[0] <= target:
            n = 1
            while candidates[0] * n <= target:
                cursum = candidates[0] * n
                curans = [candidates[0]] * n
                if cursum == target:
                    ans.append(curans)
                else:
                    result.append((cursum, curans))
                n += 1

        for can in candidates[1:]:
            if can > target:
                break
            tmp = []
            for cursum, res in result:
                n = 1
                while cursum + can * n <= target:
                    _cursum = cursum + can * n
                    _curans = res + [can] * n
                    if _cursum == target:
                        ans.append(_curans)
                    else:
                        tmp.append((_cursum, _curans))
                    n += 1
            result += tmp
        return ans
