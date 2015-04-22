# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, left, pre):
        if left == 0:
            if tuple(self.ret) not in self.set_rec:
                self.ret_list.append(self.ret[:])
                self.set_rec.add(tuple(self.ret))
        for i in range(pre + 1, len(self.candidates)):
            num = self.candidates[i]
            n_left = left - num
            if n_left >= 0:
                self.ret.append(num)
                self.dfs(n_left, i)
                self.ret.pop()

    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        self.ret, self.candidates = [], sorted(candidates)
        self.ret_list, self.set_rec = [], set()
        self.dfs(target, -1)
        return self.ret_list


if __name__ == '__main__':
    solution = Solution()
    print solution.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8)
