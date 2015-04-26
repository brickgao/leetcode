# -*- coding: utf-8 -*-


class Solution:
    # @param dividend, an integer
    # @param divisor, an integer
    # @return an integer
    def divide(self, dividend, divisor):
        upper_bound, lower_bound = (1 << 31) - 1, - (1 << 31)
        tag = -1 if dividend * divisor < 0 else 1
        dividend, divisor = abs(dividend), abs(divisor)
        if not divisor:
            return upper_bound
        ret = 0
        for i in range(31, -1, -1):
            n_divisor = divisor << i
            if n_divisor <= dividend:
                dividend -= n_divisor
                ret += 1 << i
        ret *= tag
        return ret if lower_bound <= ret <= upper_bound else upper_bound


if __name__ == '__main__':
    solution = Solution()
    print solution.divide(5, 2)
    print solution.divide(5, 0)
    print solution.divide(-2147483648, 1)
