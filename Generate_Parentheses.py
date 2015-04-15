# -*- coding: utf-8 -*-


class Solution:
    # @param n, an integer
    # @return a string[]
    def generateParenthesis(self, n):
        dp = [[] for i in range(n + 1)]
        dp[0], dp[1] = [''], ['()']
        for i in range(2, n + 1):
            for j in range(i):
                for s1 in dp[j]:
                    for s2 in dp[i - j - 1]:
                        dp[i].append('(' + s1 + ')' + s2)
        return dp[n]


if __name__ == '__main__':
    solution = Solution()
    print solution.generateParenthesis(3)
