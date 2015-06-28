# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @return {string[]}
    def findRepeatedDnaSequences(self, s):
        d, ret = {}, []
        for i in range(len(s) - 9):
            tmp = s[i:i + 10]
            if tmp in d:
                d[tmp] += 1
            else:
                d[tmp] = 1
        for key in d.keys():
            if d[key] > 1:
                ret.append(key)
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.findRepeatedDnaSequences(
        "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
    )
    print solution.findRepeatedDnaSequences(
        "AAAAAAAAAAA"
    )
