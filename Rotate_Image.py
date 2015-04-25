# -*- coding: utf-8 -*-


class Solution:
    # @param matrix, a list of lists of integers
    # @return nothing (void), do not return anything,
    # modify matrix in-place instead.
    def rotate(self, matrix):
        matrix.reverse()
        for i in range(len(matrix)):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
