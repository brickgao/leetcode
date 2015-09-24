# -*- coding: utf-8 -*-


class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num == 0:
            return 0
        return num - 9 * ((num - 1) // 9)


if __name__ == "__main__":
    solution = Solution()
    print solution.addDigits(0)
    print solution.addDigits(34)
