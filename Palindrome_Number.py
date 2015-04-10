# -*- coding: utf-8 -*-


class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        return str(x) == str(x)


if __name__ == '__main__':
    solution = Solution()
    print solution.isPalindrome(-2147447412)
