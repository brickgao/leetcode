# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @return {integer}
    def numDecodings(self, s):
        if s == "":
            return 0
        num2alpha = dict()
        dp = [0 for i in range(len(s) + 1)]
        dp[len(s)] = 1
        for i in range(26):
            num2alpha[str(i + 1)] = chr(ord('A') + i)
        for i in range(len(s) - 1, -1, -1):
            if i == len(s) - 1:
                if s[i] in num2alpha:
                    dp[i] += dp[i + 1]
            else:
                if s[i:i + 2] in num2alpha:
                    dp[i] += dp[i + 2]
                if s[i] in num2alpha:
                    dp[i] += dp[i + 1]
        return dp[0]


if __name__ == "__main__":
    solution = Solution()
    print solution.numDecodings("12")
    print solution.numDecodings("0")
