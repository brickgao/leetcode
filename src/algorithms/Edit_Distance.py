# -*- coding: utf-8 -*-


class Solution:
    # @param {string} word1
    # @param {string} word2
    # @return {integer}
    def minDistance(self, word1, word2):
        if len(word1) == 0 or len(word2) == 0:
            return max(len(word1), len(word2))
        line = [0 for i in range(len(word2) + 1)]
        dp = [line[:] for j in range(len(word1) + 1)]
        for i in range(len(word1) + 1):
            dp[i][0] = i
        for i in range(len(word2) + 1):
            dp[0][i] = i
        for i in range(len(word1)):
            for j in range(len(word2)):
                if word1[i] == word2[j]:
                    dp[i + 1][j + 1] = dp[i][j]
                else:
                    dp[i + 1][j + 1] = min(dp[i + 1][j],
                                           dp[i][j + 1],
                                           dp[i][j]) + 1
        return dp[len(word1)][len(word2)]


if __name__ == '__main__':
    solution = Solution()
    print solution.minDistance('abc', 'x')
