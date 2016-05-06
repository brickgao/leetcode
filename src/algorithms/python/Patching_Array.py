#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        upper_bound, i, result = 0, 0, 0
        while upper_bound < n:
            if i < len(nums) and upper_bound + 1 >= nums[i]:
                upper_bound, i = upper_bound + nums[i], i + 1
            else:
                result, upper_bound = result + 1, 2 * upper_bound + 1
        return result
