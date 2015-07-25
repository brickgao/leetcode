# -*- coding: utf-8 -*-


class Solution:
    # @param s, a string
    # @param wordDict, a set<string>
    # @return a boolean
    def wordBreak(self, s, wordDict):
        length = len(s)
        dp = [False for i in range(length + 1)]
        dp[length] = True
        for i in range(length, -1, -1):
            for j in range(0, i):
                tmp = s[j: i]
                dp[j] = dp[j] or (tmp in wordDict and dp[i])
        return dp[0]


if __name__ == "__main__":
    solution = Solution()
    print solution.wordBreak('leetcode', {'leet', 'code'})
