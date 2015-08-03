# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        l, r = 0, len(matrix) - 1
        while l + 1 < r:
            mid = (l + r) >> 1
            if matrix[mid][0] == target:
                return True
            elif matrix[mid][0] > target:
                r = mid
            else:
                l = mid
        if matrix[l][0] == target or matrix[r][0] == target:
            return True
        else:
            col = r if matrix[r][0] < target else l
            l, r = 0, len(matrix[0]) - 1
            while l + 1 < r:
                mid = (l + r) >> 1
                if matrix[col][mid] == target:
                    return True
                elif matrix[col][mid] > target:
                    r = mid
                else:
                    l = mid
            if matrix[col][l] == target:
                return True
            elif matrix[col][r] == target:
                return True
            else:
                return False


if __name__ == '__main__':
    solution = Solution()
    print solution.searchMatrix([[1, 3, 5, 7],
                                 [10, 11, 16, 20],
                                 [23, 30, 34, 50]], 3)
    print solution.searchMatrix([[1]], 0)
    print solution.searchMatrix([[1], [3]], 3)
    print solution.searchMatrix([[1, 3, 5, 7],
                                 [10, 11, 16, 20],
                                 [23, 30, 34, 50]], 30)
