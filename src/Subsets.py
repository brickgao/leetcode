# -*- coding: utf-8 -*-

from itertools import combinations


class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def subsets(self, nums):
        nums.sort()
        ret = [()]
        for i in range(len(nums)):
            ret += combinations(nums, i + 1)
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.subsets([1, 2, 3])
    print solution.subsets([4, 1, 0])
