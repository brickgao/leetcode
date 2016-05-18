#!/bin/env python2
# -*- coding: utf-8 -*-


class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = {"a", "e", "i", "o", "u"}
        vowel_pos, s_pos = [], [i for i in range(len(s))]
        for index, ch in enumerate(s):
            if ch.lower() in vowels:
                vowel_pos.append(index)
        for i in range(len(vowel_pos) / 2):
            pos1, pos2 = vowel_pos[i], vowel_pos[len(vowel_pos) - i - 1]
            s_pos[pos1], s_pos[pos2] = s_pos[pos2], s_pos[pos1]
        return "".join(map(lambda x: s[x], s_pos))
