# -*- coding: utf-8 -*-


class Solution:
    def setDig(self, x, y, flag):
        self.flagdl[self.n - 1 + x - y] = flag
        self.flagdr[2 * (self.n - 1) - x - y] = flag

    def getDig(self, x, y):
        l = self.flagdl[self.n - 1 + x - y]
        r = self.flagdr[2 * (self.n - 1) - x - y]
        return l or r

    def dfs(self, x, y, num):
        self.map[x][y] = 'Q'
        if num == self.n - 1:
            self.ret.append(map(lambda l: ''.join(l),
                                self.map))
            self.map[x][y] = '.'
            return
        for nx in range(self.n):
            if self.flagx[nx]:
                continue
            ny = y + 1
            if not self.flagy[ny]:
                if self.getDig(nx, ny):
                    continue
                self.flagx[nx], self.flagy[ny] = True, True
                self.setDig(nx, ny, True)
                self.dfs(nx, ny, num + 1)
                self.flagx[nx], self.flagy[ny] = False, False
                self.setDig(nx, ny, False)
        self.map[x][y] = '.'

    # @return a list of lists of string
    def solveNQueens(self, n):
        self.ret, self.n = [], n
        self.flagx = [False for i in range(n)]
        self.flagy = [False for i in range(n)]
        self.flagdr = [False for i in range(n * 2)]
        self.flagdl = [False for i in range(n * 2)]
        self.map = [['.' for i in range(n)] for i in range(n)]
        for x in range(n):
            self.flagx[x], self.flagy[0] = True, True
            self.setDig(x, 0, True)
            self.dfs(x, 0, 0)
            self.flagx[x], self.flagy[0] = False, False
            self.setDig(x, 0, False)
        return self.ret


if __name__ == '__main__':
    solution = Solution()
    for mat in solution.solveNQueens(4):
        for line in mat:
            print line
        print
