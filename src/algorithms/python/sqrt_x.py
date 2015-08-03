# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} x
    # @return {integer}
    def mySqrt(self, x):
        l, r = 0, x
        while r > l + 1:
            mid = (l + r) // 2
            if mid * mid > x:
                r = mid
            else:
                l = mid
        return r if r * r == x else l


if __name__ == '__main__':
    solution = Solution()
    print solution.mySqrt(5)
    print solution.mySqrt(1)
