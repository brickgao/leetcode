# -*- coding: utf-8 -*-


class Solution:
    def reverse(self, nums, lower_bound, upper_bound):
        length = (upper_bound - lower_bound + 1) // 2
        for i in range(length):
            first, second = lower_bound + i, upper_bound - i
            nums[first], nums[second] = nums[second], nums[first]

    # @param {integer[]} nums
    # @param {integer} k
    # @return {void} Do not return anything, modify nums in-place instead.
    def rotate(self, nums, k):
        length = len(nums)
        k %= length
        self.reverse(nums, 0, length - 1)
        self.reverse(nums, 0, k - 1)
        self.reverse(nums, k, length - 1)


if __name__ == "__main__":
    solution = Solution()
    print solution.rotate([1, 2, 3, 4, 5, 6, 7], 3)
    print solution.rotate([1], 1)
    print solution.rotate([1, 2], 2)
