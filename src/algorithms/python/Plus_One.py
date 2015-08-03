# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} digits
    # @return {integer[]}
    def plusOne(self, digits):
        left, ret = 0, []
        digits[-1] += 1
        for index in range(len(digits) - 1, -1, -1):
            digits[index] += left
            left = 1 if digits[index] >= 10 else 0
            digits[index] %= 10
            ret = [digits[index]] + ret
        if left:
            ret = [left] + ret
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.plusOne([1, 2, 3, 9])
    print solution.plusOne([9, 9])
    print solution.plusOne([1, 2, 3])
