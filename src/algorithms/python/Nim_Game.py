# -*- coding: utf-8 -*-


class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return True if n % 4 else False


if __name__ == "__main__":
    solution = Solution()
    print solution.canWinNim(4)
