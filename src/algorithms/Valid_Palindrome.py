# -*- coding: utf-8 -*-


class Solution:
    def is_valid(self, ch):
        return ch.isalpha() or ch.isdigit()

    # @param {string} s
    # @return {boolean}
    def isPalindrome(self, s):
        l, r = 0, len(s) - 1
        while l < r:
            while not self.is_valid(s[l]) and l < r:
                l += 1
            if not self.is_valid(s[l]):
                break
            while not self.is_valid(s[r]) and l < r:
                r -= 1
            if not self.is_valid(s[r]):
                break
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True


if __name__ == "__main__":
    solution = Solution()
    print solution.isPalindrome("A man, a plan, a canal: Panama")
    print solution.isPalindrome("race a car")
    print solution.isPalindrome(".,")
    print solution.isPalindrome(".a,")
    print solution.isPalindrome("1a2")
