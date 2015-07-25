# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        length = len(prices)
        ret = 0
        for i in range(1, length):
            if prices[i] > prices[i - 1]:
                ret += prices[i] - prices[i - 1]
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.maxProfit([1, 2, 3, 10, 6, 7, 1])
