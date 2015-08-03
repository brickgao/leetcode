# -*- coding: utf-8 -*-


class Solution:
    # @param n, an integer
    # @return a string
    def countAndSay(self, n):
        pre, cnt = '1', 1
        while cnt < n:
            now = ''
            p, s_len = 0, len(pre)
            while p < s_len:
                num_rec, beg_pos = pre[p], p
                while p < s_len and pre[p] == num_rec:
                    p += 1
                now += str(p - beg_pos) + num_rec
            pre = now
            cnt += 1
        return pre


if __name__ == '__main__':
    solution = Solution()
    print solution.countAndSay(5)
