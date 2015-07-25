# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @return {boolean}
    def isNumber(self, s):
        try:
            float(s)
        except:
            return False
        return True


if __name__ == '__main__':
    solution = Solution()
    print solution.isNumber('1')
    print solution.isNumber('0.1')
    print solution.isNumber('abc')
    print solution.isNumber('1 a')
    print solution.isNumber('2e10')
