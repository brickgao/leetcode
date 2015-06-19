# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def maxProduct(self, nums):
        length = len(nums)
        tmp, ret = 1, max(nums)
        for i in range(length):
            tmp *= nums[i]
            ret = max(ret, tmp)
            if tmp == 0:
                tmp = 1
        tmp = 1
        for i in range(length - 1, -1, -1):
            tmp *= nums[i]
            ret = max(ret, tmp)
            if tmp == 0:
                tmp = 1
        return ret

if __name__ == "__main__":
    solution = Solution()
    print solution.maxProduct([2, 3, -2, 4])
