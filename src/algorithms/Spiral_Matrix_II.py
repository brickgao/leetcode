# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, x, y, cnt, mv):
        if self.mat[x][y]:
            return
        self.mat[x][y] = cnt
        if mv == 1:
            if y + 1 < self.n and self.mat[x][y + 1] == 0:
                self.dfs(x, y + 1, cnt + 1, 1)
            else:
                if x + 1 < self.n:
                    self.dfs(x + 1, y, cnt + 1, 2)
                else:
                    return
        elif mv == 2:
            if x + 1 < self.n and self.mat[x + 1][y] == 0:
                self.dfs(x + 1, y, cnt + 1, 2)
            else:
                self.dfs(x, y - 1, cnt + 1, 3)
        elif mv == 3:
            if y - 1 >= 0 and self.mat[x][y - 1] == 0:
                self.dfs(x, y - 1, cnt + 1, 3)
            else:
                self.dfs(x - 1, y, cnt + 1, 4)
        else:
            if x - 1 >= 0 and self.mat[x - 1][y] == 0:
                self.dfs(x - 1, y, cnt + 1, 4)
            else:
                self.dfs(x, y + 1, cnt + 1, 1)

    # @param {integer} n
    # @return {integer[][]}
    def generateMatrix(self, n):
        if n == 0:
            return []
        self.n = n
        self.mat = [[0 for i in range(n)] for i in range(n)]
        self.dfs(0, 0, 1, 1)
        return self.mat


if __name__ == '__main__':
    solution = Solution()
    solution.generateMatrix(1)
    solution.generateMatrix(2)
    solution.generateMatrix(3)
    solution.generateMatrix(4)
