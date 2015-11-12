# -*- coding: utf-8 -*-


class NumMatrix(object):

    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        self.sum = []
        if matrix == []:
            return
        self.sum.append([0 for i in range(len(matrix[0]) + 1)])
        for i in range(len(matrix)):
            l = [0]
            for j in range(len(matrix[i])):
                l.append(l[-1] +
                         self.sum[i][j + 1] -
                         self.sum[i][j] + matrix[i][j])
            self.sum.append(l)

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        if self.sum == []:
            return 0
        else:
            return (self.sum[row2 + 1][col2 + 1] -
                    self.sum[row2 + 1][col1] -
                    self.sum[row1][col2 + 1] +
                    self.sum[row1][col1])


if __name__ == "__main__":
    # Your NumMatrix object will be instantiated and called as such:
    matrix = [
        [3, 0, 1, 4, 2],
        [5, 6, 3, 2, 1],
        [1, 2, 0, 1, 5],
        [4, 1, 0, 1, 7],
        [1, 0, 3, 0, 5]
    ]
    numMatrix = NumMatrix(matrix)
    print numMatrix.sumRegion(0, 1, 2, 3)
    print numMatrix.sumRegion(1, 2, 3, 4)
