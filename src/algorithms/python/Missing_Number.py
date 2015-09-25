# -*- coding: utf-8 -*-


class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        _sum = 0
        for num in nums:
            _sum += num
        _supposed_sum = (0 + len(nums)) * (len(nums) + 1) / 2
        return _supposed_sum - _sum


if __name__ == "__main__":
    solution = Solution()
    print solution.missingNumber([0, 1, 3])
