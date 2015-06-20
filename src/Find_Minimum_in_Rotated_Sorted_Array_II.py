# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            if nums[mid] > nums[r]:
                l = mid
            elif nums[mid] > nums[l]:
                r = mid
            else:
                r -= 1
        return nums[(l + r) >> 1]

if __name__ == "__main__":
    solution = Solution()
    print solution.findMin([3, 3, 1, 3])
