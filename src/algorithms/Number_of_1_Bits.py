# -*- coding: utf-8 -*-


class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        ret, s = 0, bin(n)[2:]
        for ch in s:
            if ch == "1":
                ret += 1
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.hammingWeight(11)
