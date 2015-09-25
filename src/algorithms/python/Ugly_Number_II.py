# -*- coding: utf-8 -*-


class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        ugly_nums = [1]
        a, b, c = 0, 0, 0
        while len(ugly_nums) < n:
            tmp1, tmp2, tmp3 = (ugly_nums[a] * 2,
                                ugly_nums[b] * 3,
                                ugly_nums[c] * 5)
            ugly_nums.append(min(tmp1, tmp2, tmp3))
            if ugly_nums[-1] == ugly_nums[a] * 2:
                a += 1
            if ugly_nums[-1] == ugly_nums[b] * 3:
                b += 1
            if ugly_nums[-1] == ugly_nums[c] * 5:
                c += 1
        return ugly_nums[-1]


if __name__ == "__main__":
    solution = Solution()
    for i in range(1, 10):
        print solution.nthUglyNumber(i)
