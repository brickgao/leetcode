#!/bin/env python2
# -*- coding: utf-8 -*-


class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.st = [[nestedList, 0]]
        self.go_to_next_valid()
        self.go_to_next_one()

    def next(self):
        """
        :rtype: int
        """
        result = self.st[-1][0][self.st[-1][1]].getInteger()
        self.st[-1][1] += 1
        self.go_to_next_valid()
        self.go_to_next_one()
        return result

    def hasNext(self):
        """
        :rtype: bool
        """
        return True if len(self.st) else False

    def go_to_next_valid(self):
        while (
            len(self.st) > 0 and
            len(self.st[-1][0]) <= self.st[-1][1]
        ):
            self.st.pop()
            if len(self.st):
                self.st[-1][1] += 1

    def go_to_next_one(self):
        while (
            len(self.st) > 0 and
            not self.st[-1][0][self.st[-1][1]].isInteger()
        ):
            self.st.append([self.st[-1][0][self.st[-1][1]].getList(), 0])
            self.go_to_next_valid()
