# -*- coding: utf-8 -*-


class Solution:
    def factorial(self, x):
        if x <= 1:
            return 1
        else:
            return x * self.factorial(x - 1)

    # @param {integer} n
    # @param {integer} k
    # @return {string}
    def getPermutation(self, n, k):
        s, cnt, e = '', k, n
        l = [(i + 1) for i in range(n)]
        while True:
            fac = self.factorial(e - 1)
            for i in range(e):
                if cnt > fac:
                    cnt -= fac
                else:
                    s, e = s + str(l[i]), e - 1
                    del l[i]
                    break
            if len(s) == n:
                break
        return s


if __name__ == '__main__':
    solution = Solution()
    print solution.getPermutation(3, 1)
    print solution.getPermutation(3, 2)
    print solution.getPermutation(3, 3)
    print solution.getPermutation(3, 4)
    print solution.getPermutation(3, 5)
    print solution.getPermutation(3, 6)
