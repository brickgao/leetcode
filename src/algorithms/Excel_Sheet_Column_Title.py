# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} n
    # @return {string}
    def convertToTitle(self, n):
        _n, s = n - 1, ""
        while True:
            s = chr(_n % 26 + ord("A")) + s
            _n = _n // 26 - 1
            if _n < 0:
                break
        return s


if __name__ == "__main__":
    solution = Solution()
    print solution.convertToTitle(1)
    print solution.convertToTitle(27)
