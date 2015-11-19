# -*- coding: utf-8 -*-


class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.sums = [0 for i in range((len(nums) << 2) + 1)]
        self.n = len(nums)
        for index, num in enumerate(nums):
            self.SGUpdate(index + 1, num, 1, self.n, 1)

    def SGPushUP(self, rt):
        self.sums[rt] = self.sums[rt << 1] + self.sums[rt << 1 | 1]

    def SGUpdate(self, pos, c, l, r, rt):
        if l == r and l == pos:
            self.sums[rt] = c
            return
        m = (l + r) >> 1
        if pos <= m:
            self.SGUpdate(pos, c, l, m, rt << 1)
        else:
            self.SGUpdate(pos, c, m + 1, r, rt << 1 | 1)
        self.SGPushUP(rt)

    def SGQuery(self, L, R, l, r, rt):
        if L <= l and r <= R:
            return self.sums[rt]
        m = (l + r) >> 1
        ret = 0
        if L <= m:
            ret += self.SGQuery(L, R, l, m, rt << 1)
        if m < R:
            ret += self.SGQuery(L, R, m + 1, r, rt << 1 | 1)
        return ret

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: int
        """
        self.SGUpdate(i + 1, val, 1, self.n, 1)

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.SGQuery(i + 1, j + 1, 1, self.n, 1)


if __name__ == "__main__":
    # Your NumArray object will be instantiated and called as such:
    nums = [1, 3, 5]
    numArray = NumArray(nums)
    print numArray.sumRange(0, 2)
    numArray.update(1, 2)
    print numArray.sumRange(0, 2)
