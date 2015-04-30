# -*- coding: utf-8 -*-


# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution:
    # @param {Interval[]} intervals
    # @param {Interval} newInterval
    # @return {Interval[]}
    def insert(self, intervals, newInterval):
        rec, ret = [], []
        intervals.append(newInterval)
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
    a, b = Interval(1, 2), Interval(3, 5)
    c, d = Interval(6, 7), Interval(8, 10)
    e, f = Interval(12, 16), Interval(4, 9)
    intervals = solution.insert([a, b, c, d, e], f)
    for interval in intervals:
        print interval.start, interval.end
