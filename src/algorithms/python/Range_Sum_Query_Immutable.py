# -*- coding: utf-8 -*-


class NumArray(object):

    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.sum = [0]
        for num in nums:
            self.sum.append(self.sum[-1] + num)

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sum[j + 1] - self.sum[i]


if __name__ == "__main__":
    # Your NumArray object will be instantiated and called as such:
    nums = [-2, 0, 3, -5, 2, -1]
    numArray = NumArray(nums)
    print numArray.sumRange(0, 2)
    print numArray.sumRange(2, 5)
    print numArray.sumRange(0, 5)
