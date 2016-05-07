#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        if preorder == "":
            return True
        st, _preorder = [0], preorder.split(",")
        for index in range(len(_preorder)):
            st[-1] += 1
            while len(st) != 0 and st[-1] == 2:
                st.pop()
            if len(st) == 0:
                return False
            if _preorder[index] != "#":
                st.append(0)
        return True if len(st) == 1 and st[-1] == 1 else False
