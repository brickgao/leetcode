# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, now, left, cnt):
        self.vis[tuple(now)] = True
        if len(now) == cnt:
            self.ret.append(now)
        else:
            for i in range(len(left)):
                tmp = now + [left[i]]
                tmp.sort()
                if tuple(tmp) not in self.vis:
                    self.dfs(tmp,
                             left[:i] + left[i + 1:],
                             cnt)

    # @param {integer[]} nums
    # @return {integer[][]}
    def subsetsWithDup(self, nums):
        self.ret = []
        for i in range(len(nums) + 1):
            self.vis = dict()
            self.dfs([], nums, i)
        return self.ret


if __name__ == "__main__":
    solution = Solution()
    print solution.subsetsWithDup([1, 2, 2])
