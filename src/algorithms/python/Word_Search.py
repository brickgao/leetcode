# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, now, x, y):
        self.vis[x][y] = True
        nstr = now + self.board[x][y]
        n_len, s_len = len(nstr), len(self.word)
        if n_len <= s_len:
            if n_len == s_len:
                self.vis[x][y] = False
                return nstr == self.word
            elif n_len != 0:
                if nstr[n_len - 1] != self.word[n_len - 1]:
                    self.vis[x][y] = False
                    return False
        else:
            self.vis[x][y] = False
            return False
        tag = False
        for mv in self.mvs:
            nx, ny = x + mv[0], y + mv[1]
            if nx < 0 or ny < 0:
                continue
            if nx >= self.m or ny >= self.n:
                continue
            if not self.vis[nx][ny]:
                tag = tag or self.dfs(nstr, nx, ny)
            if tag:
                break
        self.vis[x][y] = False
        return tag

    # @param {character[][]} board
    # @param {string} word
    # @return {boolean}
    def exist(self, board, word):
        self.word = word
        self.board = board
        self.m, self.n = len(self.board), len(self.board[0])
        line = [False for i in range(self.n)]
        self.vis = [line[:] for i in range(self.m)]
        self.mvs = [(0, -1), (-1, 0),
                    (0, 1), (1, 0)]
        for x in range(self.m):
            for y in range(self.n):
                if self.dfs('', x, y):
                    return True
        return False


if __name__ == '__main__':
    solution = Solution()
    print solution.exist(['ab'], 'ba')
    print solution.exist(['aa'], 'aa')
    print solution.exist(['ABCE',
                          'SFCS',
                          'ADEE'], 'ABCCED')
    print solution.exist(['ABCE',
                          'SFCS',
                          'ADEE'], 'SEE')
    print solution.exist(['ABCE',
                          'SFCS',
                          'ADEE'], 'ABCB')
    print solution.exist(['FYCENRD',
                          'KLNFINU',
                          'AAARAHR',
                          'NDKLPNE',
                          'ALANSAP',
                          'OOGOTPN',
                          'HPOLANO'], 'poland')
