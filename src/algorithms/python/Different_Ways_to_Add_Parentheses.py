# -*- coding: utf-8 -*-

import re


class Solution:
    def dfs(self, l):
        if len(l) == 1:
            if l[0] not in self.vis:
                self.vis.add(l[0])
                self.ret.append(eval(l[0]))
        else:
            for i in range(1, len(l), 2):
                _n_l = (l[:i - 1] +
                        ["(" + l[i - 1] + l[i] + l[i + 1] + ")"] +
                        l[i + 2:])
                self.dfs(_n_l)

    # @param {string} input
    # @return {integer[]}
    def diffWaysToCompute(self, input):
        self.vis = set()
        l, self.ret = re.split("(\D)", input), []
        self.dfs(l)
        return sorted(self.ret)


if __name__ == "__main__":
    solution = Solution()
    print solution.diffWaysToCompute("2-1-1")
    print solution.diffWaysToCompute("2*3-4*5")
    print solution.diffWaysToCompute("15-7*6+24")
