# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @param {string} t
    # @return {integer}
    def numDistinct(self, s, t):
        len_s, len_t = len(s), len(t)
        if len_s < len_t:
            return 0
        line = [0 for i in range(len_t + 1)]
        dp = [list(line) for i in range(len_s + 1)]
        for i in range(len_s + 1):
            dp[i][0] = 1
        for i in range(1, len_s + 1):
            for j in range(1, len_t + 1):
                dp[i][j] = dp[i - 1][j]
                if s[i - 1] == t[j - 1]:
                    dp[i][j] += dp[i - 1][j - 1]
        return dp[len_s][len_t]


if __name__ == "__main__":
    solution = Solution()
    print solution.numDistinct("rabbbit", "rabbit")
    print solution.numDistinct("b", "a")
    print solution.numDistinct("ccc", "c")
    print solution.numDistinct("aabb", "ab")
