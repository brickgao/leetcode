# -*- coding: utf-8 -*-


class Solution:
    # @return a string
    def intToRoman(self, num):
        roman_list = [['I', 'V', 'X'],
                      ['X', 'L', 'C'],
                      ['C', 'D', 'M'],
                      ['M']]
        ret_s, row = '', 0
        while num > 0:
            num, remainder = divmod(num, 10)
            if remainder == 0:
                tmp_s = ''
            elif remainder <= 3:
                tmp_s = roman_list[row][0] * remainder
            elif remainder == 4:
                tmp_s = roman_list[row][0] + roman_list[row][1]
            elif remainder <= 8:
                tmp_s = roman_list[row][1] + \
                    roman_list[row][0] * (remainder - 5)
            elif remainder == 9:
                tmp_s = roman_list[row][0] + roman_list[row][2]
            ret_s = tmp_s + ret_s
            row += 1
        return ret_s


if __name__ == '__main__':
    solution = Solution()
    print solution.intToRoman(1004)
