# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        _all, _zero_cnt, ret = 1, 0, []
        for num in nums:
            if num != 0:
                _all *= num
            else:
                _zero_cnt += 1
        if _zero_cnt:
            for num in nums:
                if num == 0 and _zero_cnt == 1:
                    ret.append(_all)
                else:
                    ret.append(0)
        else:
            for num in nums:
                ret.append(_all / num)
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.productExceptSelf([1, 2, 3])
    print solution.productExceptSelf([0, 0])
