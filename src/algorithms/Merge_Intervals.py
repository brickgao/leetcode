# -*- coding: utf-8 -*-


# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution:
    # @param {Interval[]} intervals
    # @return {Interval[]}
    def merge(self, intervals):
        if intervals == []:
            return []
        rec, ret = [], []
        for interval in intervals:
            rec.append((interval.start, interval.end))
        rec.sort()
        s, e = rec[0][0], rec[0][1]
        for t in rec[1:]:
            if t[0] <= e:
                e = max(t[1], e)
            else:
                ret.append(Interval(s, e))
                s, e = t[0], t[1]
        ret.append(Interval(s, e))
        return ret


if __name__ == '__main__':
    solution = Solution()
    a, b = Interval(1, 3), Interval(2, 6)
    c, d = Interval(8, 10), Interval(15, 18)
    for e in solution.merge([a, b, c, d]):
        print e.start, e.end
