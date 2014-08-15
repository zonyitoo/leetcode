class Solution:

    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        S.sort()
        ans, cur_level = [[]], [([], -1)]
        return ans + self.__solve(S, cur_level)

    def __solve(self, S, prev_level):
        cur_level = []
        for arr, idx in prev_level:
            last = None
            for nidx in range(idx + 1, len(S)):
                if S[nidx] != last:
                    cur_level.append((arr + [S[nidx]], nidx))
                    last = S[nidx]
        return [arr for arr, _ in cur_level] + self.__solve(S, cur_level) if cur_level else []
