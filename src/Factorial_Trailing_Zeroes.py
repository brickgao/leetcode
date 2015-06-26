# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} n
    # @return {integer}
    def trailingZeroes(self, n):
        ret, tmp = 0, 5
        while True:
            if tmp > n:
                break
            ret += n // tmp
            tmp *= 5
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.trailingZeroes(20)
    print solution.trailingZeroes(30)
