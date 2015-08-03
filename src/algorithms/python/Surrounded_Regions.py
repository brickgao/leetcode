# -*- coding: utf-8 -*-

from Queue import Queue


class Solution:
    def bfs(self, x, y):
        q = Queue()
        q.put((x, y))
        self.vis[x][y] = True
        self.mat[x][y] = True
        while not q.empty():
            top_x, top_y = q.get()
            for mv in self.mvs:
                nx, ny = top_x + mv[0], top_y + mv[1]
                if nx < 0 or nx >= self.m:
                    continue
                if ny < 0 or ny >= self.n:
                    continue
                if not self.vis[nx][ny] and self.board[nx][ny] == 'O':
                    q.put((nx, ny))
                    self.vis[nx][ny] = True
                    self.mat[nx][ny] = True

    # @param {character[][]} board
    # @return {void} Do not return anything, modify board in-place instead.
    def solve(self, board):
        if board == []:
            return
        self.mvs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        self.board = board
        self.m, self.n = len(board), len(board[0])
        m, n = self.m, self.n
        self.mat = [[False for i in range(n)] for j in range(m)]
        self.vis = [[False for i in range(n)] for j in range(m)]
        for y in range(self.n):
            if self.board[0][y] == 'O' and not self.vis[0][y]:
                self.bfs(0, y)
            if self.board[m - 1][y] == 'O' and not self.vis[m - 1][y]:
                self.bfs(m - 1, y)
        for x in range(m):
            if self.board[x][0] == 'O' and not self.vis[x][0]:
                self.bfs(x, 0)
            if self.board[x][n - 1] == 'O' and not self.vis[x][n - 1]:
                self.bfs(x, n - 1)
        for x in range(m):
            for y in range(n):
                if not self.mat[x][y]:
                    board[x][y] = 'X'
        return board


if __name__ == "__main__":
    solution = Solution()
    print solution.solve(
        [
            ['X', 'X', 'X', 'X'],
            ['X', 'O', 'O', 'X'],
            ['X', 'X', 'O', 'X'],
            ['X', 'O', 'X', 'X']
        ]
    )
