# -*- coding: utf-8 -*-


class Solution:
    # @return an integer
    def romanToInt(self, s):
        roman_dict = {' ': 0, 'I': 1, 'V': 5, 'X': 10,
                      'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        s += ' '
        ret = 0
        for i in range(len(s) - 1):
            if roman_dict[s[i]] < roman_dict[s[i + 1]]:
                ret -= roman_dict[s[i]]
            else:
                ret += roman_dict[s[i]]
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.romanToInt('III')
    print solution.romanToInt('IV')
    print solution.romanToInt('MIV')
