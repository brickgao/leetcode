# -*- coding: utf-8 -*-

from itertools import permutations


class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, num):
        rec_s, ret = set(), []
        for e in permutations(num, len(num)):
            if e not in rec_s:
                rec_s.add(e)
                ret.append(list(e))
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.permuteUnique([1, 1, 2])
