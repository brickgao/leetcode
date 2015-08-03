# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} n
    # @return {integer}
    def countDigitOne(self, n):
        if n <= 0:
            return 0
        ret, now = 0, 1
        while now <= n:
            _factor, _remainder = n // (now * 10), n % (now * 10)
            ret += _factor * (now)
            ret += min(now, max(_remainder - now + 1, 0))
            now *= 10
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.countDigitOne(13)
