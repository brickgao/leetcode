# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} numerator
    # @param {integer} denominator
    # @return {string}
    def fractionToDecimal(self, numerator, denominator):
        if numerator * denominator < 0:
            s = "-"
        else:
            s = ""
        numerator, denominator = abs(numerator), abs(denominator)
        s += str(numerator // denominator)
        _numerator = numerator % denominator
        if _numerator == 0:
            return s
        rec, _s, cnt = {}, "", 0
        while True:
            if _numerator in rec:
                index = rec[_numerator]
                return s + "." + _s[:index] + "(" + _s[index:] + ")"
            if _numerator == 0:
                return s + "." + _s
            rec[_numerator] = cnt
            _s += str((_numerator * 10) // denominator)
            _numerator = (_numerator * 10) % denominator
            cnt += 1


if __name__ == "__main__":
    solution = Solution()
    print solution.fractionToDecimal(1, 3)
    print solution.fractionToDecimal(2, 1)
    print solution.fractionToDecimal(2, 3)
    print solution.fractionToDecimal(1, 7)
    print solution.fractionToDecimal(-50, 8)
