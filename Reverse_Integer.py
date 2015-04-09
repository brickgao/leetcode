# -*- coding: utf-8 -*-


class Solution:
    # @return an integer
    def reverse(self, x):
        upper, lower = (1 << 31) - 1, - (1 << 31)
        if str(x)[0] == '-':
            r_num = int('-' + str(x)[:0:-1])
        else:
            r_num = int(str(x)[::-1])
        return r_num if lower < r_num < upper else 0


if __name__ == '__main__':
    solution = Solution()
    print solution.reverse(1534236469)
    print solution.reverse(-12)
    print solution.reverse(12)
    print solution.reverse(1000)
