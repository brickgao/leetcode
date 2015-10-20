# -*- coding: utf-8 -*-


class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.l = []

    def addNum(self, num):
        """
        Adds a num into the data structure.
        :type num: int
        :rtype: void
        """
        if len(self.l) == 0:
            self.l.append(num)
        else:
            pos, l, r = -1, 0, len(self.l) - 1
            while l < r - 1:
                mid = (l + r) >> 1
                if self.l[mid] == num:
                    pos = mid
                    break
                elif self.l[mid] > num:
                    r = mid
                else:
                    l = mid
            if pos == -1:
                if self.l[r] <= num:
                    pos = r
                elif self.l[l] <= num:
                    pos = l
            self.l.insert(pos + 1, num)

    def findMedian(self):
        """
        Returns the median of current data stream
        :rtype: float
        """
        mid = len(self.l) / 2
        if len(self.l) % 2 == 0:
            return float(self.l[mid] + self.l[mid - 1]) / 2.0
        else:
            return float(self.l[mid])


# Your MedianFinder object will be instantiated and called as such:
if __name__ == "__main__":
    mf = MedianFinder()
    mf.addNum(6)
    print mf.findMedian()
    mf.addNum(10)
    print mf.findMedian()
    mf.addNum(2)
    print mf.findMedian()
    mf.addNum(6)
    print mf.findMedian()
    mf.addNum(5)
    print mf.findMedian()
    mf.addNum(6)
    print mf.findMedian()
