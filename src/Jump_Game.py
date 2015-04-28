# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def canJump(self, nums):
        upper_bound = 0
        for i in range(len(nums) - 1):
            upper_bound = max(upper_bound, i + nums[i])
            if i + 1 > upper_bound:
                return False
        return True


if __name__ == '__main__':
    solution = Solution()
    print solution.canJump([2, 3, 1, 1, 4])
    print solution.canJump([3, 2, 1, 0, 4])
