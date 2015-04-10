# -*- coding: utf-8 -*-


class Solution:
    def chMatch(self, ch, p):
        if ch == p[0]:
            return True
        elif p[0] == '.':
            return True
        else:
            return False

    # @return a boolean
    def isMatch(self, s, p):
        if p == '' and s == '':
            return True
        if p == '' and not s == '':
            return False
        p_list = []
        for index, ch in enumerate(p):
            if ch == '*':
                last_pos = len(p_list) - 1
                p_list[last_pos] = ((p_list[last_pos][0],
                                     '*'))
            else:
                p_list.append((ch, None))
        s_len, p_len = len(s), len(p_list)
        if s == '':
            flag = True
            for p_s in p_list:
                if not p_s[1] == '*':
                    flag = False
                    break
            return flag
        dp = [[False for i in range(s_len + 1)] for j in range(p_len + 1)]
        for i in range(p_len - 1, -2, -1):
            for j in range(s_len - 1, -2, -1):
                if (j + 1 >= s_len and i + 1 >= p_len) or dp[i + 1][j + 1]:
                    if i >= 0 and j >= 0 and self.chMatch(s[j], p_list[i]):
                        dp[i][j] = True
                    if i >= 0 and p_list[i][1] == '*':
                        dp[i][j + 1] = True
                    if j >= 0 and i + 1 < p_len \
                       and p_list[i + 1][1] == '*' \
                       and self.chMatch(s[j], p_list[i + 1]):
                        dp[i + 1][j] = True
        return dp[0][0]


if __name__ == '__main__':
    solution = Solution()
    print solution.isMatch('aa', 'a')
    print solution.isMatch('aa', 'aa')
    print solution.isMatch('aaa', 'aa')
    print solution.isMatch('aa', 'a*')
    print solution.isMatch('aa', '.*')
    print solution.isMatch('ab', '.*')
    print solution.isMatch('aab', 'c*a*b')
    print solution.isMatch('', '')
    print solution.isMatch('', 'b')
    print solution.isMatch('', 'a*b*')
