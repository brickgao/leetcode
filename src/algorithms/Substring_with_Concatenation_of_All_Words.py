# -*- coding: utf-8 -*-

from collections import Counter


class Solution:
    # @param S, a string
    # @param L, a string[]
    # @return an integer[]
    def findSubstring(self, S, L):
        l_d, ret_l = dict(Counter(L)), []
        for i in range(len(S) - len(L[0]) * len(L) + 1):
            tmp_d = {}
            for j in range(len(L)):
                sub_s = S[i + j * len(L[0]):i + (j + 1) * len(L[0])]
                if sub_s in tmp_d:
                    tmp_d[sub_s] += 1
                else:
                    tmp_d[sub_s] = 1
            if l_d == tmp_d:
                ret_l.append(i)
        return ret_l


if __name__ == '__main__':
    solution = Solution()
    print solution.findSubstring('barfoothefoobarman', ['foo', 'bar'])
    print solution.findSubstring('a', ['a'])
    print solution.findSubstring('abababab', ['a', 'b', 'a'])
