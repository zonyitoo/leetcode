class Solution:

    def numDistinct(self, S, T):
        '''
        Given a string S and a string T, count the number of distinct subsequences of T in S.

        '''
        if not S:
            return 0
        dp = [[0 for _ in range(len(T))] for _ in range(len(S))]

        for i in range(len(S)):
            for j in range(min(i + 1, len(T))):
                if S[i] == T[j]:
                    dp[i][j] = 1 if i == 0 or j == 0 else dp[i - 1][j - 1]
                if i > j:
                    dp[i][j] += dp[i - 1][j]
        return dp[len(S) - 1][len(T) - 1]
