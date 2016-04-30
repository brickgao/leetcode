#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [0 if i == 0 else -1 for i in range(amount + 1)]
        for coin in coins:
            for i in range(coin, amount + 1):
                if (
                    dp[i - coin] != -1 and
                    (dp[i] == -1 or dp[i] > dp[i - coin] + 1)
                ):
                    dp[i] = dp[i - coin] + 1
        return dp[amount]
