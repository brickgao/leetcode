# -*- coding: utf-8 -*-


class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        common_s = '' if not len(strs) else strs[0]
        for s in strs[1:]:
            len1, len2 = len(s), len(common_s)
            index, tag = 0, True
            for index in range(min(len1, len2)):
                if common_s[index] != s[index]:
                    tag = False
                    break
            if tag and s != '':
                common_s = common_s[:index + 1]
            else:
                common_s = common_s[:index]
        return common_s


if __name__ == '__main__':
    solution = Solution()
    print solution.longestCommonPrefix(['abaaa', 'absss'])
    print solution.longestCommonPrefix(['', 'absss'])
    print solution.longestCommonPrefix(['c', 'c'])
    print solution.longestCommonPrefix(['cc', 'c'])
