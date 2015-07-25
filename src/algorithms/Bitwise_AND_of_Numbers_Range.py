# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def rangeBitwiseAnd(self, m, n):
        if m == 0:
            return 0
        s_ret, s_num = "", bin(max(m, n))[2:]
        tmp, cnt = 1, -1
        while tmp <= m or tmp <= n:
            _m, _n = m // tmp, n // tmp
            if _m == _n:
                s_ret = s_num[cnt] + s_ret
            else:
                s_ret = "0" + s_ret
            tmp, cnt = tmp << 1, cnt - 1
        return int(s_ret, 2)


if __name__ == "__main__":
    solution = Solution()
    print solution.rangeBitwiseAnd(0, 0)
    print solution.rangeBitwiseAnd(2, 2)
    print solution.rangeBitwiseAnd(5, 7)
