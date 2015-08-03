# -*- coding: utf-8 -*-

from itertools import product


class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        if digits == '':
            return []
        num_dict = {2: 'abc', 3: 'def', 4: 'ghi',
                    5: 'jkl', 6: 'mno', 7: 'pqrs',
                    8: 'tuv', 9: 'wxyz'}
        s_l, ret_l = [], []
        for digit in digits:
            s_l.append(num_dict[int(digit)])
        for p in product(*s_l):
            ret_l.append(''.join(p))
        return ret_l


if __name__ == '__main__':
    solution = Solution()
    print solution.letterCombinations('23')
