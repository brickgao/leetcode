# -*- coding: utf-8 -*-


class Solution:
    # @param {float} x
    # @param {integer} n
    # @return {float}
    def myPow(self, x, n):
        tmp, ret = x, 1.0
        if n == 0:
            return 1.0
        elif n > 0:
            while n > 0:
                if n & 1:
                    ret *= tmp
                tmp, n = tmp * tmp, n >> 1
        else:
            n = abs(n)
            while n > 0:
                if n & 1:
                    ret /= tmp
                tmp, n = tmp * tmp, n >> 1
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.myPow(2.0, 7)
    print solution.myPow(3.89707, 2)
    print solution.myPow(34.00515, -3)
