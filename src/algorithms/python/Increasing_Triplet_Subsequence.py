#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        minn, mid = 0xFFFFFFFFFF, 0xFFFFFFFFFF
        for num in nums:
            if num < minn:
                minn = num
            elif num > minn:
                if mid < num:
                    return True
                mid = num
        return False
