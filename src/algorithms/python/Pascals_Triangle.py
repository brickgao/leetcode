# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} numRows
    # @return {integer[][]}
    def generate(self, numRows):
        ret = []
        if numRows >= 1:
            ret.append([1])
        if numRows >= 2:
            ret.append([1, 1])
        for i in range(3, numRows + 1):
            tmp_l = [1]
            for j in range(len(ret[i - 2]) - 1):
                tmp_num = ret[i - 2][j] + ret[i - 2][j + 1]
                tmp_l.append(tmp_num)
            tmp_l.append(1)
            ret.append(tmp_l)
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.generate(1)
    print solution.generate(2)
    print solution.generate(3)
    print solution.generate(4)
    print solution.generate(5)
