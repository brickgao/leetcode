# -*- coding: utf-8 -*-


class Solution:
    def isValidMat(self, mat):
        rec_set = set()
        for l in mat:
            for num in l:
                if num == '.':
                    continue
                if num in rec_set:
                    return False
                else:
                    rec_set.add(num)
        return True

    def isValidLine(self, line):
        rec_set = set()
        for num in line:
            if num == '.':
                continue
            if num in rec_set:
                return False
            else:
                rec_set.add(num)
        return True

    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        flag = True
        for line in board:
            flag = flag and self.isValidLine(line)
        for i in range(9):
            flag = (flag and
                    self.isValidLine(map(lambda l: l[i],
                                         board)))
        for i in range(3):
            for j in range(3):
                flag = (flag and
                        self.isValidMat(map(lambda l: l[j * 3:(j + 1) * 3],
                                            board[i * 3:(i + 1) * 3])))
        return flag


if __name__ == '__main__':
    solution = Solution()
