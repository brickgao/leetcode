# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[][]} dungeon
    # @return {integer}
    def calculateMinimumHP(self, dungeon):
        m, n = len(dungeon), len(dungeon[0])
        dp = [[0xffffffff for i in range(n)] for i in range(m)]
        dp[m - 1][n - 1] = max(- dungeon[m - 1][n - 1], 0)
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i < m - 1:
                    dp[i][j] = min(
                        dp[i][j],
                        max(
                            0,
                            dp[i + 1][j] - dungeon[i][j]
                        )
                    )
                if j < n - 1:
                    dp[i][j] = min(
                        dp[i][j],
                        max(
                            0,
                            dp[i][j + 1] - dungeon[i][j]
                            )
                    )
        return dp[0][0] + 1


if __name__ == "__main__":
    solution = Solution()
    print solution.calculateMinimumHP(
        [
            [-2, -3, 3],
            [-5, -10, 1],
            [10, 30, -5]
        ]
    )
    print solution.calculateMinimumHP([[0, 0]])
    print solution.calculateMinimumHP([[100]])
    print solution.calculateMinimumHP([[-3, 5]])
    print solution.calculateMinimumHP(
        [
            [1, -3, 3],
            [0, -2, 0],
            [-3, -3, -3]
        ]
    )
    print solution.calculateMinimumHP(
        [
            [1, -2, 3],
            [2, -2, -2]
        ]
    )
