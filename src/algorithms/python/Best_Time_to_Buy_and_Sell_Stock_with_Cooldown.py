# -*- coding: utf-8 -*-


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 1:
            return 0
        if len(prices) == 2:
            return max(prices[1] - prices[0], 0)
        dp = [[0 for x in range(2)] for y in prices]
        dp[0][0], dp[0][1] = -prices[0], 0
        dp[1][0], dp[1][1] = (max(-prices[0], -prices[1]),
                              max(prices[1] - prices[0], 0))
        for i in range(2, len(prices)):
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        return dp[len(prices) - 1][1]


if __name__ == "__main__":
    solution = Solution()
    print solution.maxProfit([1, 2, 3, 0, 2])
