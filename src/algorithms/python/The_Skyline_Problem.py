# -*- coding: utf-8 -*-


class SegmentTree:
    def __init__(self, size):
        self.rec = [0 for i in range((size + 1) << 2)]
        self.col = [0 for i in range((size + 1) << 2)]

    def push_up(self, rt):
        self.rec[rt] = max(self.rec[rt << 1], self.rec[rt << 1 | 1])

    def push_down(self, rt, m):
        if self.col[rt]:
            self.col[rt << 1] = max(self.col[rt << 1], self.col[rt])
            self.col[rt << 1 | 1] = max(self.col[rt << 1 | 1], self.col[rt])
            self.rec[rt << 1] = max(self.rec[rt << 1], self.col[rt])
            self.rec[rt << 1 | 1] = max(self.rec[rt << 1 | 1], self.col[rt])
            self.col[rt] = 0

    def update(self, L, R, c, l, r, rt):
        if L <= l and r <= R:
            self.rec[rt] = max(self.rec[rt], c)
            self.col[rt] = max(self.col[rt], c)
            return
        self.push_down(rt, r - l + 1)
        mid = (l + r) >> 1
        if L <= mid:
            self.update(L, R, c, l, mid, rt << 1)
        if R > mid:
            self.update(L, R, c, mid + 1, r, rt << 1 | 1)
        self.push_up(rt)

    def query(self, pos, l, r, rt):
        if l == r:
            return self.rec[rt]
        self.push_down(rt, r - l + 1)
        mid = (l + r) >> 1
        if pos <= mid:
            return self.query(pos, l, mid, rt << 1)
        else:
            return self.query(pos, mid + 1, r, rt << 1 | 1)


class Solution:
    # @param {integer[][]} buildings
    # @return {integer[][]}
    def getSkyline(self, buildings):
        if buildings == []:
            return []
        self.nums, vis = [], {}
        for _l, _r, _h in buildings:
            if _l not in vis:
                self.nums.append(_l)
                vis[_l] = True
            if _r not in vis:
                self.nums.append(_r)
                vis[_r] = True
        self.nums.sort()
        for index, num in enumerate(self.nums):
            vis[num] = index
        seg_tree = SegmentTree(len(self.nums))
        for _l, _r, _h in buildings:
            l_pos = vis[_l] + 1
            r_pos = vis[_r] + 1
            seg_tree.update(l_pos, r_pos - 1, _h, 1, len(self.nums), 1)
        rec = []
        for i in range(len(self.nums)):
            rec.append(seg_tree.query(i + 1, 1, len(self.nums), 1))
        ret = [[self.nums[0], rec[0]]]
        for i in range(1, len(self.nums)):
            if rec[i] != rec[i - 1]:
                ret.append([self.nums[i], rec[i]])
        return ret


if __name__ == "__main__":
    solution = Solution()
    l = []
    for i in range(10001):
        l.append([i, 10001, 10000 - i])
    print solution.getSkyline(
        [[2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 10], [19, 24, 8]]
    )
    print solution.getSkyline(l)
