# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def firstMissingPositive(self, nums):
        i = 0
        while i < len(nums):
            if nums[i] == i + 1 or nums[i] <= 0 or nums[i] > len(nums):
                i += 1
            elif nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
            else:
                i += 1
        i = 0
        while i < len(nums) and nums[i] == i + 1:
            i += 1
        return i + 1


if __name__ == '__main__':
    solution = Solution()
    print solution.firstMissingPositive([1, 2, 0])
    print solution.firstMissingPositive([3, 4, -1, 1])
