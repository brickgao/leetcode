# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def build(self, l, r):
        mid = (l + r) >> 1
        node = TreeNode(self.nums[mid])
        if mid - l:
            node.left = self.build(l, mid)
        if r - mid - 1:
            node.right = self.build(mid + 1, r)
        return node

    # @param {integer[]} nums
    # @return {TreeNode}
    def sortedArrayToBST(self, nums):
        if nums == []:
            return None
        self.nums = nums
        return self.build(0, len(nums))


if __name__ == "__main__":
    solution = Solution()
    node = solution.sortedArrayToBST([1, 2, 3])
    print node.val, node.left.val, node.right.val
