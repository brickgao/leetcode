# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s1
    # @param {string} s2
    # @param {string} s3
    # @return {boolean}
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3):
            return False
        len1, len2 = len(s1) + 1, len(s2) + 1
        len3 = len(s3) + 1
        dp = [[False for i in range(len1)] for j in range(len3)]
        dp[0][0] = True
        for i in range(1, len3):
            for j in range(0, min(i + 1, len1)):
                k = i - j
                if j >= len1 or k >= len2:
                    continue
                if j >= 1 and s1[j - 1] == s3[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1] or dp[i][j]
                if k >= 1 and s2[k - 1] == s3[i - 1]:
                    dp[i][j] = dp[i - 1][j] or dp[i][j]
        return dp[len3 - 1][len1 - 1]


if __name__ == "__main__":
    solution = Solution()
    print solution.isInterleave("aabcc", "dbbca", "aadbbcbcac")
    print solution.isInterleave("aabcc", "dbbca", "aadbbbaccc")
