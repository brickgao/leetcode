# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @return {integer}
    def titleToNumber(self, s):
        ret = 0
        for i in range(len(s)):
            ret *= 26
            ret += ord(s[i]) - ord('A') + 1
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.titleToNumber("AA")
