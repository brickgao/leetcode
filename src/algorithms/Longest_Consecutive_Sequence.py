# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def longestConsecutive(self, nums):
        d = {}
        ret = 0
        for num in nums:
            d[num] = -1
        length = len(nums)
        for num in nums:
            rec = 0
            if d[num] == -1:
                for i in xrange(1, length + 1):
                    if num - i in d:
                        if d[num - i] != -1:
                            rec = i
                            break
                    else:
                        d[num - i + 1] = 1
                        rec = i - 1
                        break
                for i in xrange(rec, 0, -1):
                    d[num - i + 1] = d[num - i] + 1
            ret = max(ret, d[num])
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.longestConsecutive([0])
    print solution.longestConsecutive([100, 4, 200, 1, 3, 2])
