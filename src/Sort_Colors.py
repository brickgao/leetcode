# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {void} Do not return anything, modify nums in-place instead.
    def sortColors(self, nums):
        b, w, r = 0, 0, len(nums) - 1
        while w <= r:
            if nums[w] == 1:
                w += 1
            elif nums[w] == 0:
                nums[w], nums[b] = nums[b], nums[w]
                b, w = b + 1, w + 1
            else:
                while w < r and nums[r] == 2:
                    r -= 1
                nums[w], nums[r] = nums[r], nums[w]
                r -= 1


if __name__ == '__main__':
    solution = Solution()
    print solution.sortColors([1, 2, 0, 0, 0])
