# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s1
    # @param {string} s2
    # @return {boolean}
    def isScramble(self, s1, s2):
        len1, len2 = len(s1), len(s2)
        if len1 != len2:
            return False
        if len1 == 0:
            return True
        line = [False for i in range(len1)]
        dp = [[line[:] for i in range(len1)] for i in range(len1)]
        for i in range(len1):
            for j in range(len1):
                dp[0][i][j] = True if s1[i] == s2[j] else False
        for k in range(2, len1 + 1):
            for i in range(len1 - k, -1, -1):
                for j in range(len1 - k, -1, -1):
                    tag = False
                    for m in range(1, k):
                        tag = ((dp[m - 1][i][j] and
                                dp[k - m - 1][i + m][j + m]) or
                               (dp[m - 1][i][j + k - m] and
                                dp[k - m - 1][i + m][j]))
                        if tag:
                            break
                    dp[k - 1][i][j] = tag
        return dp[len1 - 1][0][0]


if __name__ == "__main__":
    solution = Solution()
    print solution.isScramble("rgtae", "great")
    print solution.isScramble("rgeat", "great")
