# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        d_s, d_t = {}, {}
        for ch in s:
            if ch in d_s:
                d_s[ch] += 1
            else:
                d_s[ch] = 1
        for ch in t:
            if ch in d_t:
                d_t[ch] += 1
            else:
                d_t[ch] = 1
        return d_s == d_t


if __name__ == "__main__":
    solution = Solution()
    print solution.isAnagram("anagram", "nagaram")
    print solution.isAnagram("rat", "cat")
