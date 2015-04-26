# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def jump(self, nums):
        upper_bound, rec_bound, cnt = 0, 0, 0
        for i in range(len(nums) - 1):
            upper_bound = max(upper_bound, i + nums[i])
            if i == rec_bound:
                cnt += 1
                rec_bound = upper_bound
        return cnt


if __name__ == '__main__':
    solution = Solution()
    print solution.jump([2, 3, 1, 1, 4])
