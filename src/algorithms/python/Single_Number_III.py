# -*- coding: utf-8 -*-


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        xor_res = 0
        for num in nums:
            xor_res ^= num
        xor_res = xor_res ^ (xor_res - 1) & xor_res
        a, b = 0, 0
        for num in nums:
            if xor_res & num:
                a ^= num
            else:
                b ^= num
        return [a, b]


if __name__ == "__main__":
    solution = Solution()
    print solution.singleNumber([1, 2, 1, 3, 2, 5])
