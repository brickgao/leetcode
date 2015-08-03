# -*- coding: utf-8 -*-


class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        if matrix == []:
            return []
        m, n = len(matrix), len(matrix[0])
        cnt = min(m, n)
        ret = []
        beg_pos = 0
        while cnt > 0:
            row_l = map(lambda l: l[n - beg_pos - 1], matrix)
            row_b = map(lambda l: l[beg_pos], matrix)
            ret += matrix[beg_pos][beg_pos:n - beg_pos]
            ret += row_l[beg_pos + 1:m - beg_pos - 1]
            if beg_pos != m - beg_pos - 1:
                ret += matrix[m - beg_pos - 1][beg_pos:n - beg_pos][::-1]
            if beg_pos != n - beg_pos - 1:
                ret += row_b[beg_pos + 1:m - beg_pos - 1][::-1]
            cnt, beg_pos = cnt - 2, beg_pos + 1
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.spiralOrder([[1, 2, 3],
                                [4, 5, 6],
                                [7, 8, 9]])
    print solution.spiralOrder([[1, 2, 3, 4],
                                [5, 6, 7, 8],
                                [9, 10, 11, 12],
                                [13, 14, 15, 16]])
    print solution.spiralOrder([[1],
                                [2]])
    print solution.spiralOrder([[7],
                                [9],
                                [6]])
