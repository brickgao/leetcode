#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        result, step = [0], 1
        while len(result) <= num:
            for i in range(step):
                if len(result) > num:
                    break
                result.append(result[- step] + 1)
            step <<= 1
        return result
