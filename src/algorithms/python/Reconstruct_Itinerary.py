#!/bin/env python2
# -*- coding: utf-8 -*-

from collections import defaultdict


class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        paths, result = ["JFK"], []
        mp = defaultdict(lambda: [])
        for u, v in tickets:
            mp[u].append(v)
        for u in mp.keys():
            mp[u].sort()
        while len(paths) != 0:
            now = paths[-1]
            if len(mp[now]) != 0:
                paths.append(mp[now][0])
                mp[now].remove(mp[now][0])
            else:
                result.append(paths[-1])
                paths.pop()
        return result[::-1]
