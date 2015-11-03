# -*- coding: utf-8 -*-


class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []:
            return 0
        n = len(nums)
        dp = [1 for i in range(n)]
        for i in xrange(n):
            maxn = 0
            for j in xrange(i):
                if nums[i] > nums[j] and maxn < dp[j]:
                    maxn = dp[j]
            dp[i] = maxn + 1
        return max(dp)


if __name__ == "__main__":
    solution = Solution()
    print solution.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])
