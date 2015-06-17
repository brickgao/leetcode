# -*- coding: utf-8 -*-


# Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

    def __repr__(self):
        return str((self.x, self.y))


class Solution:
    # @param {Point[]} points
    # @return {integer}
    def maxPoints(self, points):
        ret, rec = 0, {}
        s_x, s_y = set(), set()
        for point in points:
            x, y = point.x, point.y
            s_x.add(x)
            s_y.add(y)
            if (x, y) not in rec:
                rec[(x, y)] = 1
            else:
                rec[(x, y)] += 1
        l_x, l_y = list(s_x), list(s_y)
        l_x.sort(), l_y.sort()
        l_rec = sorted(rec.keys())
        length = len(l_rec)
        if length == 1:
            return rec[l_rec[0]]
        for i in range(length):
            for j in range(i):
                point1, point2 = l_rec[j], l_rec[i]
                if point1[0] == point2[0] and point1[1] == point2[1]:
                    tmp = rec[(point1[0], point1[1])]
                else:
                    tmp = rec[(point1[0], point1[1])] + \
                        rec[(point2[0], point2[1])]
                k1, k2 = (point1[1] - point2[1]), (point1[0] - point2[0])
                if k2 == 0:
                    pos1, pos2 = l_y.index(point1[1]), l_y.index(point2[1])
                    for y in range(pos1 + 1, pos2):
                        if (point1[0], l_y[y]) in rec:
                            tmp += rec[(point1[0], l_y[y])]
                else:
                    pos1, pos2 = l_x.index(point1[0]), l_x.index(point2[0])
                    for x in range(pos1 + 1, pos2):
                        if ((l_x[x] - point1[0]) * k1) % k2:
                            continue
                        _x = l_x[x]
                        _y = point1[1] + (l_x[x] - point1[0]) * k1 / k2
                        if (_x, _y) in rec:
                            tmp += rec[(_x, _y)]
                ret = max(tmp, ret)
        return ret


if __name__ == "__main__":
    solution = Solution()
    l = [(0, 0), (0, 0)]
    l = map(lambda x: Point(x[0], x[1]), l)
    print solution.maxPoints(l)
