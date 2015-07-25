# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[][]} obstacleGrid
    # @return {integer}
    def uniquePathsWithObstacles(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        for i in range(n):
            if obstacleGrid[0][i]:
                break
            dp[0][i] = 1
        for i in range(m):
            if obstacleGrid[i][0]:
                break
            dp[i][0] = 1
        for i in range(1, m):
            for j in range(1, n):
                if not obstacleGrid[i][j]:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[m - 1][n - 1]


if __name__ == '__main__':
    solution = Solution()
    print solution.uniquePathsWithObstacles([[0, 0, 0],
                                             [0, 1, 0],
                                             [0, 0, 0]])
