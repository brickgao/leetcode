# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        if nums == []:
            return []
        pre, beg, ret = -1, -1, []
        nums.append(nums[-1] + 10)
        for i in range(len(nums)):
            if i == 0:
                pre, beg = nums[i], i
            else:
                if pre + 1 == nums[i]:
                    pre = nums[i]
                else:
                    if i - beg > 1:
                        ret.append("{0}->{1}".format(nums[beg], nums[i - 1]))
                    else:
                        ret.append(str(nums[i - 1]))
                    pre, beg = nums[i], i
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.summaryRanges([0, 1, 2, 4, 5, 7])
