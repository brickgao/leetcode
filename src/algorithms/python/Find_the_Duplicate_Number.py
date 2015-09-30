# -*- coding: utf-8 -*-


class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        fast, slow = len(nums) - 1, len(nums) - 1
        while True:
            fast = nums[nums[fast] - 1] - 1
            slow = nums[slow] - 1
            if fast == slow:
                break
        slow = len(nums) - 1
        while fast != slow:
            slow = nums[slow] - 1
            fast = nums[fast] - 1
        return slow + 1


if __name__ == "__main__":
    solution = Solution()
    print solution.findDuplicate([1, 2, 2])
    print solution.findDuplicate([2, 1, 4, 3, 3])
    print solution.findDuplicate([2, 5, 1, 1, 4, 3])
