# -*- coding: utf-8 -*-


class Solution(object):
    def dfs(self, beg1, beg2, end2):
        _s1, _s2 = self.s[beg1:beg2], self.s[beg2:end2]
        if _s1.startswith('0') and len(_s1) > 1:
            return
        if _s2.startswith('0') and len(_s2) > 1:
            return
        _sum = int(_s1) + int(_s2)
        for end3 in range(end2 + 1, len(self.s) + 1):
            _s3 = self.s[end2:end3]
            if not (_s3.startswith('0') and len(_s3) > 1) and _sum == int(_s3):
                if end3 == len(self.s):
                    self.ret = True
                else:
                    self.dfs(beg2, end2, end3)

    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        self.ret = False
        self.s = str(num)
        for i in range(1, len(self.s) - 1):
            _s1 = self.s[:i]
            for j in range(i + 1, len(self.s)):
                _s2 = self.s[i:j]
                self.dfs(0, i, j)
        return self.ret


if __name__ == "__main__":
    solution = Solution()
    print solution.isAdditiveNumber(112358)
    print solution.isAdditiveNumber(199100199)
