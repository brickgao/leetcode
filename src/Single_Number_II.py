# -*- coding: utf-8 -*-

from ctypes import c_int


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        ret = 0
        for i in range(32):
            cnt = 0
            for num in nums:
                cnt += 1 if num & (1 << i) else 0
            cnt %= 3
            ret += (cnt << i)
        return c_int(ret).value


if __name__ == "__main__":
    solution = Solution()
    print solution.singleNumber([1, 1, 1, 2, 3, 2, 2])
    print solution.singleNumber([-2, -2, 1, 1, -3, 1, -3, -3, -4, -2])
