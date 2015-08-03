# -*- coding: utf-8 -*-


class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return an integer
    def strStr(self, haystack, needle):
        next = [-1 for i in range(len(needle))]
        for i in range(1, len(needle)):
            k = next[i - 1]
            while k != -1 and needle[k] != needle[i - 1]:
                k = next[k]
            next[i] = k + 1
        i, j = 0, 0
        while i < len(haystack) and j < len(needle):
            if j == -1 or haystack[i] == needle[j]:
                i, j = i + 1, j + 1
            else:
                j = next[j]
        if j == len(needle):
            return i - j
        else:
            return -1


if __name__ == '__main__':
    solution = Solution()
    print solution.strStr('testone', 'to')
    print solution.strStr('mississippi', 'issip')
