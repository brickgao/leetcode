# -*- coding: utf-8 -*-

from collections import OrderedDict


class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @param {integer} t
    # @return {boolean}
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        if k < 1 or t < 0:
            return False
        _t, rec = max(t, 1), OrderedDict()
        for i in range(len(nums)):
            _key = nums[i] / _t
            for j in range(_key - 1, _key + 2):
                if j in rec and abs(nums[i] - rec[j]) <= t:
                    return True
            rec[_key] = nums[i]
            if i >= k:
                rec.popitem(last=False)
        return False


if __name__ == "__main__":
    solution = Solution()
    print solution.containsNearbyAlmostDuplicate(
        [1, 2], 2, 1
    )
    print solution.containsNearbyAlmostDuplicate(
        [0, 2147483647], 1, 2147483647
    )
    print solution.containsNearbyAlmostDuplicate(
        [1], 1, 1
    )
