# -*- coding: utf-8 -*-


class Solution:
    # @return a string
    def convert(self, s, nRows):
        if nRows == 1:
            return s
        s_list = ['' for i in range(nRows)]
        row, step = 0, 1
        for ch in s:
            s_list[row] += ch
            if row == nRows - 1 and step == 1:
                step = -1
            if row == 0 and step == -1:
                step = 1
            row += step
        ret_s = ''
        for s in s_list:
            ret_s += s
        return ret_s


if __name__ == '__main__':
    solution = Solution()
    print solution.convert('PAYPALISHIRING', 3)
