#!/bin/env python2
# -*- coding: utf-8 -*-

from bisect import bisect_left, bisect_right, insort_left


class Solution(object):

    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        result, now_sum, l = 0, 0, [0]
        for num in nums:
            now_sum += num
            lower_pos = bisect_left(l, now_sum - upper)
            upper_pos = bisect_right(l, now_sum - lower)
            result += upper_pos - lower_pos
            insort_left(l, now_sum)
        return result
