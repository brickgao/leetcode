# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} k
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, k, prices):
        length = len(prices)
        if k > length / 2:
            ret = 0
            for i in range(1, length):
                if prices[i] > prices[i - 1]:
                    ret += prices[i] - prices[i - 1]
            return ret
        else:
            k *= 2
            dp = [[-0xfffffffff, -0xfffffffff] for i in range(k + 1)]
            dp[0][1] = 0
            for i in range(length):
                for j in range(1, min(k + 1, i + 2)):
                    dp[j][0] = max(dp[j][0], dp[j - 1][1] - prices[i])
                    if j != 1:
                        dp[j][1] = max(dp[j][1], dp[j - 1][0] + prices[i])
            ret = max(map(max, dp))
            return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.maxProfit(2, [1, 2, 3, 4, 5])
    print solution.maxProfit(1, [1, 2])
