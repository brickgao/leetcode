# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} n
    # @return {integer}
    def climbStairs(self, n):
        dp = [0 if i else 1 for i in range(n + 1)]
        for i in range(1, n + 1):
            if i > 1:
                dp[i] = dp[i - 2] + dp[i - 1]
            else:
                dp[i] = dp[i - 1]
        return dp[n]


if __name__ == '__main__':
    solution = Solution()
    print solution.climbStairs(4)
