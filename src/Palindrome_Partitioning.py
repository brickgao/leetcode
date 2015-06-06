# -*- coding: utf-8 -*-


class Solution:
    def ispalindrome(self, s):
        if s not in self.d:
            self.d[s] = (s == s[::-1])
        return self.d[s]

    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        self.d = {}
        dp = [[[]]]
        for i in range(len(s)):
            tmp = []
            for j in range(i + 1):
                if self.ispalindrome(s[j:i + 1]):
                    for last_status in dp[j]:
                        tmp.append(last_status + [s[j:i + 1]])
            dp.append(tmp)
        return dp[-1]


if __name__ == "__main__":
    solution = Solution()
    print solution.partition("aab")
    print solution.partition("ab")
    print solution.partition("efe")
    print solution.partition("eee")
    print solution.partition("amanaplanacanalpanama")
