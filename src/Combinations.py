# -*- coding: utf-8 -*-

from itertools import combinations


class Solution:
    # @param {integer} n
    # @param {integer} k
    # @return {integer[][]}
    def combine(self, n, k):
        return list(combinations([i + 1 for i in range(n)], k))


if __name__ == '__main__':
    solution = Solution()
    print solution.combine(4, 2)
