# -*- coding: utf-8 -*-


class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i, tmp = 0, 0
        while i < len(nums):
            if nums[i] == 0:
                tmp = max(tmp, i)
                while nums[tmp] == 0:
                    tmp += 1
                    if tmp >= len(nums):
                        return
                nums[i], nums[tmp] = nums[tmp], nums[i]
            i += 1


if __name__ == "__main__":
    solution = Solution()
    solution.moveZeroes([1, 3, 12])
    solution.moveZeroes([0, 1, 0, 3, 12])
