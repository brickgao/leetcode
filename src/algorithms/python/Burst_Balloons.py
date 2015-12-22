# -*- coding: utf-8 -*-


class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1] + [num for num in nums if num > 0] + [1]
        n = len(nums)
        dp = [[0 for i in xrange(n)] for j in xrange(n)]
        for i in xrange(0, n - 2):
            dp[i][i + 2] = nums[i] * nums[i + 1] * nums[i + 2]
        for i in xrange(4, n + 1):
            for j in xrange(0, n - i + 1):
                beg, end = j, j + i - 1
                beg_mul_end = nums[beg] * nums[end]
                _tmp = dp[beg][end - 1] + beg_mul_end * nums[end - 1]
                if _tmp > dp[beg][end]:
                    dp[beg][end] = _tmp
                _tmp = dp[beg + 1][end] + beg_mul_end * nums[beg + 1]
                if _tmp > dp[beg][end]:
                    dp[beg][end] = _tmp
                for k in xrange(beg + 2, end - 2 + 1):
                    _tmp = dp[beg][k] + dp[k][end] + beg_mul_end * nums[k]
                    if _tmp > dp[beg][end]:
                        dp[beg][end] = _tmp
        return dp[0][n - 1]


if __name__ == "__main__":
    pass
