# -*- coding: utf-8 -*-


class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        ret = bin(n)[2:][::-1]
        ret += (32 - len(ret)) * "0"
        return int(ret, 2)


if __name__ == "__main__":
    solution = Solution()
    print solution.reverseBits(43261596)
