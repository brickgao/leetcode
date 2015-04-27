# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def maxSubArray(self, nums):
        sums = [0 for i in range(len(nums) + 1)]
        for i in range(0, len(nums)):
            sums[i + 1] = sums[i] + nums[i]
        maxn, max_pos = sums[len(sums) - 1], len(sums) - 1
        minn, min_pos = sums[0], 0
        max_l = [(None, None) for i in range(len(sums))]
        min_l = max_l[:]
        for i in range(len(sums)):
            if minn > sums[i]:
                minn, min_pos = sums[i], i
            min_l[i] = (minn, min_pos)
        for i in range(len(sums) - 1, -1, -1):
            if maxn < sums[i]:
                maxn, max_pos = sums[i], i
            max_l[i] = (maxn, max_pos)
        maxn, max_slice = sums[0], (0, 0)
        for i in range(len(sums)):
            if max_l[i][0] - min_l[i][0] > maxn:
                maxn = max_l[i][0] - min_l[i][0]
                max_slice = (min_l[i][1], max_l[i][1])
        return max(nums) if max_slice == (0, 0) else maxn


if __name__ == '__main__':
    solution = Solution()
    print solution.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4])
    print solution.maxSubArray([-1])
