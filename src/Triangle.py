# -*- coding: utf-8 -*-


class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        if triangle == []:
            return 0
        else:
            l = [triangle[0][0]]
        row, col = 1, 0
        while row < len(triangle):
            tmp_l = [0 for i in range(len(l) + 1)]
            for i in range(1, len(l)):
                tmp_l[i] = min(
                    l[i - 1] + triangle[row][i],
                    l[i] + triangle[row][i]
                )
            tmp_l[0] = l[0] + triangle[row][0]
            tmp_l[-1] = l[-1] + triangle[row][-1]
            row += 1
            l = tmp_l
        return min(l)


if __name__ == "__main__":
    solution = Solution()
    print solution.minimumTotal([
        [2],
        [3, 4],
        [6, 5, 7],
        [4, 1, 8, 3]
    ])
    print solution.minimumTotal([[-10]])
