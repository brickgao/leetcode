# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        vis = {}
        for num in nums:
            if num not in vis:
                vis[num] = 1
            else:
                return True
        return False


if __name__ == "__main__":
    solution = Solution()
    print solution.containsDuplicate([1, 1, 2])
    print solution.containsDuplicate([1, 2, 3])
