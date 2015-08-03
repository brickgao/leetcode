# -*- coding: utf-8 -*-

from math import sqrt


class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n < 2:
            return 0
        e = int(sqrt(n)) + 1
        vis, ret = [False for i in range(n)], n - 2
        vis[0], vis[1] = True, True
        for num in range(2, n, 2):
            vis[num] = True
        if n > 2:
            ret = n / 2
        for num in range(3, e, 2):
            vis[num] = True
            for _num in range(num * num, n, num * 2):
                if not vis[_num]:
                    ret -= 1
                    vis[_num] = True
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.countPrimes(2)
    print solution.countPrimes(10)
    print solution.countPrimes(10000)
