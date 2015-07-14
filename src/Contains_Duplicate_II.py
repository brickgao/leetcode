# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        rec = {}
        for i in range(len(nums)):
            if nums[i] in rec:
                if i - rec[nums[i]] <= k:
                    return True
            rec[nums[i]] = i
        return False


if __name__ == "__main__":
    solution = Solution()
    print solution.containsNearbyDuplicate([99, 99], 2)
