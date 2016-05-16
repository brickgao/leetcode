#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        _num = num - 1
        return True if num > 0 and num & _num == 0 and _num % 3 == 0 else False
