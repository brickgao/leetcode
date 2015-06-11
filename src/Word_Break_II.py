# -*- coding: utf-8 -*-


class Solution:
    # @param s, a string
    # @param wordDict, a set<string>
    # @return a string[]
    def wordBreak(self, s, wordDict):
        self.wordDict = set(wordDict)
        self.length = len(s)
        self.dp = [False for i in range(self.length + 1)]
        self.dp[self.length] = True
        for i in range(self.length, -1, -1):
            for j in range(0, i):
                tmp = s[j: i]
                self.dp[j] = self.dp[j] or (tmp in self.wordDict and self.dp[i])
        if not self.dp[0]:
            return []
        self.dp = [[] for i in range(self.length + 1)]
        self.dp[self.length] = [[]]
        for i in range(self.length, -1, -1):
            for j in range(0, i):
                tmp = s[j: i]
                if tmp in self.wordDict:
                    self.dp[j] += map(lambda l: [tmp] + l, self.dp[i])
        return map(lambda l:" ".join(l), self.dp[0])
        


if __name__ == "__main__":
    solution = Solution()
    print solution.wordBreak(
        "catsanddog",
        {"cat", "cats", "and", "sand", "dog"}
    )
    print solution.wordBreak(
        "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}
    )
