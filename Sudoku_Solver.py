# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, x, y):
        tag = True
        for line in self.mat:
            if '.' in line:
                tag = False
                break
        if tag:
            return True
        if self.mat[x][y] == '.':
            line_x_set = set(self.mat[x])
            line_y_set = set(map(lambda l: l[y],
                             self.mat))
            mat = map(lambda l: l[(y // 3) * 3:(y // 3 + 1) * 3],
                      self.mat[(x // 3) * 3:(x // 3 + 1) * 3])
            mat_set = set(mat[0] + mat[1] + mat[2])
            left_nums = ((self.num_set - line_x_set) &
                         (self.num_set - line_y_set) &
                         (self.num_set - mat_set))
            for num in left_nums:
                self.mat[x][y] = num
                if y == 8:
                    nxt_x, nxt_y = x + 1, 0
                else:
                    nxt_x, nxt_y = x, y + 1
                if x < 9 and self.dfs(nxt_x, nxt_y):
                    return True
            self.mat[x][y] = '.'
        else:
            if y == 8:
                nxt_x, nxt_y = x + 1, 0
            else:
                nxt_x, nxt_y = x, y + 1
            if x < 9 and self.dfs(nxt_x, nxt_y):
                return True
        return False

    # @param board, a 9x9 2D array
    # Solve the Sudoku by modifying the input board in-place.
    # Do not return any value.
    def solveSudoku(self, board):
        self.mat = map(list, board)
        self.num_set = set([str(i) for i in range(1, 10)])
        self.dfs(0, 0)
        for x in range(9):
            board[x] = ''.join(self.mat[x])
        for line in board:
            print line


if __name__ == '__main__':
    solution = Solution()
    solution.solveSudoku(['..9748...',
                          '7........',
                          '.2.1.9...',
                          '..7...24.',
                          '.64.1.59.',
                          '.98...3..',
                          '...8.3.2.',
                          '........6',
                          '...2759..'])
