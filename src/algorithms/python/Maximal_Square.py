# -*- coding: utf-8 -*-


class Solution:
    # @param {character[][]} matrix
    # @return {integer}
    def maximalSquare(self, matrix):
        if matrix == []:
            return 0
        m, n = len(matrix), len(matrix[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        for i in range(n):
            if matrix[0][i] == "1":
                dp[0][i] = 1
        for i in range(m):
            if matrix[i][0] == "1":
                dp[i][0] = 1
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == "0":
                    dp[i][j] = 0
                else:
                    dp[i][j] = max(
                        1,
                        min(dp[i - 1][j - 1],
                            dp[i][j - 1],
                            dp[i - 1][j]) + 1
                    )
        ret = 0
        for i in range(0, m):
            for j in range(0, n):
                ret = max(ret, dp[i][j])
        return ret * ret


if __name__ == "__main__":
    solution = Solution()
    print solution.maximalSquare(
        [
            "10100",
            "10111",
            "11111",
            "10010"
        ]
    )
    print solution.maximalSquare(["0"])
    print solution.maximalSquare(["1"])
