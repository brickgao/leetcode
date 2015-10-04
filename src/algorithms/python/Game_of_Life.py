# -*- coding: utf-8 -*-


class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if board == []:
            return
        m, n = len(board), len(board[0])
        diffs = [
            (0, 1), (1, 0), (0, -1), (-1, 0),
            (1, 1), (1, -1), (-1, 1), (-1, -1)
        ]
        new_board = [[0 for i in range(n)] for j in range(m)]
        for x in range(m):
            for y in range(n):
                new_board[x][y] = board[x][y]
        for x in range(m):
            for y in range(n):
                cnt = 0
                for x_diff, y_diff in diffs:
                    n_x, n_y = x + x_diff, y + y_diff
                    if n_x < 0 or n_x >= m or n_y < 0 or n_y >= n:
                        continue
                    cnt += board[n_x][n_y]
                if cnt < 2:
                    new_board[x][y] = 0
                elif cnt == 2:
                    new_board[x][y] = board[x][y]
                elif cnt == 3:
                    new_board[x][y] = 1
                else:
                    new_board[x][y] = 0
        for x in range(m):
            for y in range(n):
                board[x][y] = new_board[x][y]


if __name__ == "__main__":
    solution = Solution()
    input_board = [
        [0, 0]
    ]
    solution.gameOfLife(input_board)
    for line in input_board:
        print line
