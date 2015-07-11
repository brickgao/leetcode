# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        if nums == []:
            return 0
        if len(nums) == 1:
            return nums[0]
        ret, dp = 0, [[0, 0] for num in nums]
        dp[0] = [0, nums[0]]
        for i in range(1, len(nums) - 1):
            for j in range(i):
                dp[i][1] = max(dp[i][1], dp[j][0] + nums[i])
                dp[i][0] = max(dp[i][0], dp[j][0], dp[j][1])
            for j in range(i - 1):
                dp[i][1] = max(dp[i][1], dp[j][1] + nums[i])
        ret = max(ret, dp[-2][0], dp[-2][1])
        dp = [[0, 0] for num in nums]
        dp[0] = [0, 0]
        for i in range(1, len(nums)):
            for j in range(i):
                dp[i][1] = max(dp[i][1], dp[j][0] + nums[i])
                dp[i][0] = max(dp[i][0], dp[j][0], dp[j][1])
            for j in range(i - 1):
                dp[i][1] = max(dp[i][1], dp[j][1] + nums[i])
        ret = max(ret, dp[-1][0], dp[-1][1])
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.rob([1, 2, 3])
    print solution.rob([1])
