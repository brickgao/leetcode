# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        now = n
        vis = dict()
        while now != 1:
            if now not in vis:
                vis[now] = True
            else:
                return False
            tmp, s_now = 0, str(now)
            for single_num in s_now:
                tmp += int(single_num) * int(single_num)
            now = tmp
        return True


if __name__ == "__main__":
    solution = Solution()
    print solution.isHappy(19)
