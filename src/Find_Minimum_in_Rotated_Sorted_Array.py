# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[l] <= nums[mid] <= nums[r]:
                return nums[l]
            elif nums[l] >= nums[mid] >= nums[r]:
                return nums[r]
            else:
                if nums[mid] < nums[l]:
                    r = mid
                else:
                    l = mid
        return nums[l]

if __name__ == "__main__":
    solution = Solution()
    print solution.findMin([4, 5, 6, 7, 0, 1, 2])
    print solution.findMin([1])
