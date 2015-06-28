# -*- coding: utf-8 -*-


def my_cmp(x, y):
    return int(y + x) - int(x + y)


class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        s_nums = map(str, nums)
        s_nums.sort(cmp=my_cmp)
        return str(int(''.join(s_nums)))


if __name__ == "__main__":
    solution = Solution()
    print solution.largestNumber([3, 30, 34, 5, 9, 10])
    print solution.largestNumber([128, 12])
    print solution.largestNumber([121, 12])
