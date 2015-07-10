# -*- coding: utf-8 -*-


class Solution:
    # @param {character[][]} board
    # @param {string[]} words
    # @return {string[]}
    def findWords(self, board, words):
        self.trie = {}
        self.ret, self.board = set(), board
        self.m, self.n = len(board), len(board[0])
        self.vis = [[False for i in range(self.n)] for j in range(self.m)]
        for word in words:
            node = self.trie
            for ch in word:
                if ch not in node:
                    node[ch] = {}
                node = node[ch]
            node["."] = True
        self.mv = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for x in range(self.m):
            for y in range(self.n):
                self.dfs(x, y, "")
        return list(self.ret)

    def dfs(self, x, y, now):
        _s = now + self.board[x][y]
        node = self.trie
        for ch in _s:
            if ch not in node:
                return
            else:
                node = node[ch]
        if "." in node:
            self.ret.add(_s)
        self.vis[x][y] = True
        for _mv_x, _mv_y in self.mv:
            _x, _y = _mv_x + x, _mv_y + y
            if 0 <= _x < self.m and 0 <= _y < self.n and not self.vis[_x][_y]:
                self.dfs(_x, _y, _s)
        self.vis[x][y] = False


if __name__ == "__main__":
    solution = Solution()
    print solution.findWords(
        [
            ["o", "a", "a", "n"],
            ["e", "t", "a", "e"],
            ["i", "h", "k", "r"],
            ["i", "f", "l", "v"]
        ],
        ["oath", "pea", "eat", "rain"]
    )
