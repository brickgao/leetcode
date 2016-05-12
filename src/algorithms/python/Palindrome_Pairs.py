#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):

    def is_palindrome(self, s):
        for i in range(len(s) / 2):
            if s[i] != s[len(s) - i - 1]:
                break
        else:
            return True
        return False

    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        d, result = {}, []
        for index, word in enumerate(words):
            d[word[::-1]] = index
        if "" in d:
            for i in range(len(words)):
                if self.is_palindrome(words[i]) and words[i] != "":
                    result.append([d[""], i])
        for i in range(len(words)):
            for j in range(len(words[i])):
                part1, part2 = words[i][:j], words[i][j:]
                if part1 in d and self.is_palindrome(part2) and d[part1] != i:
                    result.append([i, d[part1]])
                if part2 in d and self.is_palindrome(part1) and d[part2] != i:
                    result.append([d[part2], i])
        return result
