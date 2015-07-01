# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        dp = [[0, 0] for i in range(len(nums) + 1)]
        for i in range(len(nums)):
            for j in range(i + 1):
                dp[i + 1][1] = max(dp[i + 1][1], dp[j][0] + nums[i])
                dp[i + 1][0] = max(dp[i + 1][0], dp[j][0], dp[j][1])
            for j in range(i):
                dp[i + 1][1] = max(dp[i + 1][1], dp[j][1] + nums[i])
        return max(dp[len(nums)])


if __name__ == "__main__":
    solution = Solution()
    print solution.rob([2, 1, 1, 2])
