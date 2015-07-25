# -*- coding: utf-8 -*-

from math import ceil


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def maximumGap(self, nums):
        maxn, minn = -0xfffffffffff, 0xfffffffffff
        length = len(nums)
        if length < 2:
            return 0
        for num in nums:
            maxn, minn = max(maxn, num), min(minn, num)
        capacity = int(ceil((maxn - minn) / float(length)))
        rec = [(0xfffffffffff, -0xfffffffffff) for i in range(length + 1)]
        for num in nums:
            pos = (num - minn) / capacity
            rec[pos] = (min(rec[pos][0], num), max(rec[pos][1], num))
        ret, pre = 0, 0
        for i in range(1, length + 1):
            if rec[i][0] == 0xfffffffffff:
                continue
            ret = max(ret, rec[i][0] - rec[pre][1])
            pre = i
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.maximumGap([1, 3, 10, 11, 12])
    print solution.maximumGap([2, 99999999])
