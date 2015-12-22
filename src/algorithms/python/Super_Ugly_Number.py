# -*- coding: utf-8 -*-


class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        ugly_nums, prime_indexs = [1], [0 for i in range(len(primes))]
        for i in range(n - 1):
            minn = primes[0] * ugly_nums[prime_indexs[0]]
            for j in range(1, len(primes)):
                minn = min(minn, primes[j] * ugly_nums[prime_indexs[j]])
            for j in range(0, len(primes)):
                if primes[j] * ugly_nums[prime_indexs[j]] == minn:
                    prime_indexs[j] += 1
            ugly_nums.append(minn)
        return ugly_nums[-1]
