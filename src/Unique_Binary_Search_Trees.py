# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} n
    # @return {integer}
    def numTrees(self, n):
        rec = [0 for i in range(n + 1)]
        rec[0], rec[1] = 1, 1
        for length in range(2, n + 1):
            for root in range(1, length + 1):
                rec[length] += (rec[root - 1] *
                                rec[length - root])
        return rec[n]

if __name__ == "__main__":
    solution = Solution()
    print solution.numTrees(2)
    print solution.numTrees(3)
    print solution.numTrees(4)
