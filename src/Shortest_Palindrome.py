# -*- coding: utf-8 -*-


class Solution:

    def get_shortest_palindrome(self, s):
        next = [-1 for i in range(len(s))]
        for i in range(1, len(s)):
            k = next[i - 1]
            while k != -1 and s[k] != s[i - 1]:
                k = next[k]
            next[i] = k + 1
        i, j = 0, len(s) - 1
        while i < len(s) and j > i:
            if i == -1 or s[i] == s[j]:
                i += 1
                j -= 1
            else:
                i = next[i]
        if s[:i * 2 + 1] == s[:i * 2 + 1][::-1]:
            return s[i * 2 + 1:][::-1] + s
        else:
            return s[i * 2:][::-1] + s

    # @param {string} s
    # @return {string}
    def shortestPalindrome(self, s):
        return self.get_shortest_palindrome(s)

        
if __name__ == "__main__":
    solution = Solution()
    print solution.shortestPalindrome("aacecaaa")
