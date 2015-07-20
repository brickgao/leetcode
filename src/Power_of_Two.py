# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} n
    # @return {boolean}
    def isPowerOfTwo(self, n):
        if n <= 0:
            return False
        return all(map(lambda ch: ch == "0", bin(n)[3:]))


if __name__ == "__main__":
    solution = Solution()
    print solution.isPowerOfTwo(1)
    print solution.isPowerOfTwo(2)
    print solution.isPowerOfTwo(3)
    print solution.isPowerOfTwo(4)
    print solution.isPowerOfTwo(5)
