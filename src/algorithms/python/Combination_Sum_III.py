# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, num, left, cnt):
        if cnt == 0:
            if left == 0:
                self.ret.append(list(self.now))
            return
        for i in range(num + 1, 10):
            self.now.append(i)
            self.dfs(i, left - i, cnt - 1)
            self.now.pop()

    # @param {integer} k
    # @param {integer} n
    # @return {integer[][]}
    def combinationSum3(self, k, n):
        self.ret, self.now = [], []
        self.dfs(0, n, k)
        return self.ret


if __name__ == "__main__":
    solution = Solution()
    print solution.combinationSum3(3, 7)
    print solution.combinationSum3(3, 9)
