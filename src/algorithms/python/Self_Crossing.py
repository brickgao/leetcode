#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        if len(x) <= 3:
            return False
        i = 2
        while i < len(x) and x[i] > x[i - 2]:
            i += 1
        if i >= len(x):
            return False
        if (
            (i >= 4 and x[i] >= x[i - 2] - x[i - 4]) or
            (i == 3 and x[i] == x[i - 2])
        ):
            x[i - 1] -= x[i - 3]
        i += 1
        while i < len(x):
            if x[i] >= x[i - 2]:
                return True
            i += 1
        return False
