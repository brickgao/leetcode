# -*- coding: utf-8 -*-


class Solution:
    # @param nums, an integer[]
    # @return an integer
    def findPeakElement(self, nums):
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] < nums[mid + 1]:
                l = mid + 1
            else:
                r = mid
        return (l + r) >> 1


if __name__ == "__main__":
    solution = Solution()
    print solution.findPeakElement([1, 2, 3, 1])
