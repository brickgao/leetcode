# -*- coding: utf-8 -*-

class Solution:
    # @param {string} s
    # @return {integer}
    def minCut(self, s):
        self.d = {}
        dp = [0 for i in range(len(s) + 1)]
        is_p = [[False for i in range(len(s))] for j in range(len(s))]
        for i in range(len(s) + 1):
           dp[i] = len(s) - i 
        for i in range(len(s)):
            for j in range(i, -1, -1):
                if i - j + 1 == 1:
                    is_p[j][i] = True
                elif i - j + 1 == 2:
                    is_p[j][i] = (s[i] == s[j])
                else:
                    is_p[j][i] = is_p[j + 1][i - 1] and (s[i] == s[j])
        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)):
                if is_p[i][j]:
                    dp[i] = min(dp[i], dp[j + 1] + 1)
        return dp[0] - 1


if __name__ == "__main__":
    solution = Solution()
    print solution.minCut("aab")
