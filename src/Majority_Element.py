# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
        cnt, now = 1, nums[0]
        for i in range(1, len(nums)):
            if nums[i] == now:
                cnt += 1
            else:
                cnt -= 1
            if cnt < 0:
                cnt, now = 1, nums[i]
        return now


if __name__ == "__main__":
    solution = Solution()
    print solution.majorityElement([1, 2, 3, 3, 1, 3])
