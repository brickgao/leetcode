# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} rowIndex
    # @return {integer[]}
    def getRow(self, rowIndex):
        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1, 1]
        else:
            pre = [1, 1]
        for i in range(1, rowIndex):
            tmp_l = [1]
            for j in range(len(pre) - 1):
                tmp_num = pre[j] + pre[j + 1]
                tmp_l.append(tmp_num)
            tmp_l.append(1)
            pre = tmp_l
        return pre


if __name__ == "__main__":
    solution = Solution()
    print solution.getRow(1)
    print solution.getRow(2)
    print solution.getRow(3)
    print solution.getRow(4)
    print solution.getRow(5)
    print solution.getRow(6)
