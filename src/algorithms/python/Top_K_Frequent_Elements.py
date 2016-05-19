#!/bin/env python2
# -*- coding: utf-8 -*-

from collections import Counter


class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        counter = Counter(nums)
        counter_l = sorted([(counter[key], key) for key in counter])
        return map(lambda x: x[1], counter_l[-k:])[::-1]
