# -*- coding: utf-8 -*-


class Solution:
    def valid(self, x, y):
        if 0 <= x < self.m and 0 <= y < self.n:
            return True
        else:
            return False

    def dfs(self, x, y):
        self.vis[x][y] = True
        for _x, _y in self.mv:
            nx, ny = x + _x, y + _y
            if (self.valid(nx, ny) and
                    not self.vis[nx][ny] and
                    self.grid[nx][ny] == "1"):
                    self.dfs(nx, ny)

    # @param {character[][]} grid
    # @return {integer}
    def numIslands(self, grid):
        self.mv = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        if grid == []:
            return 0
        ret = 0
        self.grid = grid
        self.vis = [[False for i in grid[0]] for j in grid]
        self.m, self.n = len(grid), len(grid[0])
        for x in range(self.m):
            for y in range(self.n):
                if self.grid[x][y] == "1" and not self.vis[x][y]:
                    self.dfs(x, y)
                    ret += 1
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.numIslands(
        [
            "11110", "11010",
            "11000", "00000"
        ]
    )
    print solution.numIslands(
        [
            "11000", "11000",
            "00100", "00011"
        ]
    )
