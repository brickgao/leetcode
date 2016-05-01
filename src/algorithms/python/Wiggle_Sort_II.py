#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):

    def get_median(self, nums):
        l, r, k = -214748364, 214748364, (len(nums) - 1) / 2 + 1
        while l < r:
            mid = l + (r - l) / 2 if l < 0 and r > 0 else (l + r) / 2
            larger_cnt, smaller_cnt, tag = 0, 0, 0
            for num in nums:
                if num < mid:
                    smaller_cnt += 1
                    if smaller_cnt > k - 1:
                        tag = 1
                        break
                elif num > mid:
                    larger_cnt += 1
                    if larger_cnt > len(nums) - k:
                        tag = -1
                        break
            if tag == 0:
                return mid
            else:
                l, r = (mid + 1, r) if tag < 0 else (l, mid)
        return -1

    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        median, mod = self.get_median(nums), len(nums) | 1
        i, j, k = 1 % mod, 1 % mod, (2 * len(nums) - 1) % mod
        for t in range(len(nums)):
            if nums[j] > median:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = (i + 2) % mod, (j + 2) % mod
            elif nums[j] < median:
                nums[j], nums[k] = nums[k], nums[j]
                k = (k - 2 + mod) % mod
            else:
                j = (j + 2) % mod
