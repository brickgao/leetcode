#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        pow_of_three_limit = 1853020188851841
        return False if n <= 0 or pow_of_three_limit % n != 0 else True
