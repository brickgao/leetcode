# -*- coding: utf-8 -*-


class Solution:
    def binary_seach(self, l, r, val):
        _l, _r = l, r
        while _l < _r - 1:
            _mid = (_l + _r) >> 1
            if self.sum[_mid] == val:
                return _mid
            elif self.sum[_mid] > val:
                _r = _mid
            else:
                _l = _mid
        if self.sum[_l] >= val:
            return _l
        elif self.sum[_r] >= val:
            return _r
        else:
            return -1

    # @param {integer} s
    # @param {integer[]} nums
    # @return {integer}
    def minSubArrayLen(self, s, nums):
        self.sum = [0 for i in range(len(nums) + 1)]
        for i in range(len(nums)):
            self.sum[i + 1] = self.sum[i] + nums[i]
        if self.sum[-1] < s:
            return 0
        ret = len(nums)
        for i in range(len(nums)):
            val = self.sum[i] + s
            pos = self.binary_seach(i, len(nums), val)
            if pos != -1:
                ret = min(ret, pos - i)
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.minSubArrayLen(7, [2, 3, 1, 2, 4, 3])
    print solution.minSubArrayLen(6, [10, 2, 3])
