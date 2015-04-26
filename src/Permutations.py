# -*- coding: utf-8 -*-

from itertools import permutations


class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        ret = permutations(num, len(num))
        ret = map(list, ret)
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.permute([1, 2, 3])
