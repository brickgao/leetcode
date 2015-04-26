# -*- coding: utf-8 -*-

from collections import Counter


class Solution:
    # @param {string[]} strs
    # @return {string[]}
    def anagrams(self, strs):
        d, ret = {}, []
        for index, s in enumerate(strs):
            key = ''.join(sorted(s))
            if key not in d:
                d[key] = [index]
            else:
                d[key].append(index)
        for key in d:
            if len(d[key]) >= 2:
                ret += map(lambda i: strs[i], d[key])
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.anagrams(['aa', 'abb', 'ava'])
    print solution.anagrams(['', ''])
