#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        results = [0, 0, 1, 2, 4, 6, 9]
        while len(results) <= n:
            results.append(results[-3] * 3)
        return results[n]
