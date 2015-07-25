# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        rec, vis = dict(), set()
        for index in range(len(s)):
            ch_s, ch_t = s[index], t[index]
            if ch_s not in rec:
                if ch_t in vis:
                    return False
                rec[ch_s] = ch_t
                vis.add(ch_t)
            else:
                if rec[ch_s] != ch_t:
                    return False
        return True


if __name__ == "__main__":
    solution = Solution()
    print solution.isIsomorphic("egg", "add")
    print solution.isIsomorphic("foo", "bar")
    print solution.isIsomorphic("paper", "title")
