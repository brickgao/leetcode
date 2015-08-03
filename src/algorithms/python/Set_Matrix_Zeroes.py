# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[][]} matrix
    # @return {void} Do not return anything, modify matrix in-place instead.
    def setZeroes(self, matrix):
        x_list, y_list = set(), set()
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if not matrix[i][j]:
                    x_list.add(i)
                    y_list.add(j)
        for i in x_list:
            for j in range(len(matrix[0])):
                matrix[i][j] = 0
        for i in range(len(matrix)):
            for j in y_list:
                matrix[i][j] = 0


if __name__ == '__main__':
    solution = Solution()
    print solution.setZeroes([[1, 2, 0],
                              [0, 1, 1],
                              [1, 2, 3]])
