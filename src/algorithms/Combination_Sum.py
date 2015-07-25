# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, left, pre):
        if left == 0:
            self.ret_list.append(sorted(self.ret))
        for num in self.candidates:
            if pre != -1 and num > pre:
                return
            n_left = left - num
            if n_left >= 0:
                self.ret.append(num)
                self.dfs(n_left, num)
                self.ret.pop()

    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        self.ret, self.candidates = [], sorted(candidates)
        self.ret_list = []
        self.dfs(target, -1)
        return self.ret_list


if __name__ == '__main__':
    solution = Solution()
    print solution.combinationSum([2, 3, 6, 7], 7)
