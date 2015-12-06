# -*- coding: utf-8 -*-


class Solution(object):
    def push_up(self, rt):
        self.sum[rt] = self.sum[rt << 1] + self.sum[rt << 1 | 1]

    def update(self, add, p, l, r, rt):
        if l == r:
            self.sum[rt] += add
            return
        mid = (l + r) >> 1
        if p <= mid:
            self.update(add, p, l, mid, rt << 1)
        else:
            self.update(add, p, mid + 1, r, rt << 1 | 1)
        self.push_up(rt)

    def query(self, L, R, l, r, rt):
        if L <= l and r <= R:
            return self.sum[rt]
        mid = (l + r) >> 1
        ret = 0
        if L <= mid:
            ret += self.query(L, R, l, mid, rt << 1)
        if R > mid:
            ret += self.query(L, R, mid + 1, r, rt << 1 | 1)
        return ret

    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        sorted_nums = sorted(nums)
        mp, cnt = dict(), 1
        for num in sorted_nums:
            mp[num] = cnt
            cnt += 1
        n = len(nums)
        self.sum, result = [0 for i in range((n + 1) << 2)], []
        for num in nums[::-1]:
            if mp[num] > 1:
                result.append(self.query(1, mp[num] - 1, 1, n, 1))
            else:
                result.append(0)
            self.update(1, mp[num], 1, n, 1)
        return result[::-1]


if __name__ == "__main__":
    solution = Solution()
    print solution.countSmaller([5, 2, 6, 1])
    print solution.countSmaller([-1, -2])
