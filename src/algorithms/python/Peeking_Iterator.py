# -*- coding: utf-8 -*-

from itertools import tee


class Iterator(object):
    def __init__(self, nums):
        """
        Initializes an iterator object to the beginning of a list.
        :type nums: List[int]
        """
        self.iterator = iter(nums)

    def hasNext(self):
        """
        Returns true if the iteration has more elements.
        :rtype: bool
        """
        try:
            self.iterator, _next = tee(self.iterator)
            _next.next()
        except:
            return False
        return True

    def next(self):
        """
        Returns the next element in the iteration.
        :rtype: int
        """
        return self.iterator.next()


class PeekingIterator(object):
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self._tag = False
        self._lastnum = 0

    def peek(self):
        """
        Returns the next element in the iteration
        without advancing the iterator.
        :rtype: int
        """
        if not self._tag:
            self._tag = True
            self._lastnum = self.iterator.next()
        return self._lastnum

    def next(self):
        """
        :rtype: int
        """
        if not self._tag:
            self._lastnum = self.iterator.next()
        self._tag = False
        return self._lastnum

    def hasNext(self):
        """
        :rtype: bool
        """
        if not self._tag:
            return self.iterator.hasNext()
        else:
            return True


if __name__ == "__main__":
    iter = PeekingIterator(Iterator([1, 2, 3, 4]))
    while iter.hasNext():
        val = iter.peek()
        iter.next()
