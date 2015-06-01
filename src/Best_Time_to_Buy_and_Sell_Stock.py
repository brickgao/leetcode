# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        ret, tmp = 0, 0
        for i in range(1, len(prices)):
            tmp += prices[i] - prices[i - 1]
            tmp = max(tmp, 0)
            ret = max(tmp, ret)
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.maxProfit([1, 2, 4])
