# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} n
    # @return {integer[]}
    def grayCode(self, n):
        ret = [0]
        total, cnt = (1 << n), 1
        vis = [False for i in range(total + 1)]
        vis[0] = True
        num = '0' * n
        while True:
            for i in range(n - 1, -1, -1):
                tmp_s = (num[:i] +
                         ('0' if num[i] == '1' else '1') +
                         num[i + 1:])
                tmp_num = int(tmp_s, 2)
                if not vis[tmp_num]:
                    num = tmp_s
                    vis[tmp_num] = True
                    ret.append(tmp_num)
                    cnt += 1
                    break
            if cnt == total:
                break
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.grayCode(1)
    print solution.grayCode(2)
    print solution.grayCode(3)
    print solution.grayCode(4)
    print solution.grayCode(5)
