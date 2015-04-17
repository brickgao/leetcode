# -*- coding: utf-8 -*-


class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        try:
            while True:
                A.remove(elem)
        except:
            pass
        return len(A)
