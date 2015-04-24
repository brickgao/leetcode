# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @param {string} p
    # @return {boolean}
    def isMatch(self, s, p):
        s_len, p_len = len(s), len(p)
        if p_len - p.count('*') > s_len:
            return False
        if not p.count('*') and s_len > p_len:
            return False
        dp = [True if not i else False for i in range(s_len + 1)]
        for ch in p:
            if ch != '*':
                for i in range(s_len - 1, -1, -1):
                    dp[i + 1] = dp[i] and (ch == '?' or ch == s[i])
            else:
                for i in range(1, s_len + 1):
                    dp[i] = dp[i - 1] or dp[i]
            dp[0] = dp[0] and ch == '*'
        return dp[s_len]

if __name__ == '__main__':
    solution = Solution()
    print solution.isMatch('aa', 'a')
    print solution.isMatch('aa', 'aa')
    print solution.isMatch('aaa', 'aa')
    print solution.isMatch('aa', '*')
    print solution.isMatch('aa', '??')
