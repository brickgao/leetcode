# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        maxn, pre = 0, 0
        length = len(prices)
        l = [0 for i in range(length)]
        r = list(l)
        tmp, maxn = 0, 0
        for i in range(1, length):
            tmp += prices[i] - prices[i - 1]
            tmp = max(tmp, 0)
            maxn = max(maxn, tmp)
            l[i] = maxn
        tmp, maxn = 0, 0
        for i in range(length - 2, -1, -1):
            tmp += prices[i + 1] - prices[i]
            tmp = max(tmp, 0)
            maxn = max(maxn, tmp)
            r[i] = maxn
        ret = 0
        for i in range(0, length):
            ret = max(ret, l[i] + r[i])
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.maxProfit([1, 2, 3, 1, 7, 2, 10])
    print solution.maxProfit([2, 1])
