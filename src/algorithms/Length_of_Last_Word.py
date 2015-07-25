# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLastWord(self, s):
        for word in s.split(' ')[::-1]:
            if word != '':
                return len(word)
        return 0


if __name__ == '__main__':
    solution = Solution()
    print solution.lengthOfLastWord('Hello World')
