# -*- coding: utf-8 -*-


class Solution:
    # @return a string
    def longestPalindrome(self, s):
        if len(s) <= 1:
            return s
        s_pr = '^' + '#'.join(s) + '$'
        p = [0 for i in s_pr]
        mx, id, index = 0, 0, 1
        while True:
            p[index] = min(p[2 * id - index], mx - index) if mx > index else 1
            while s_pr[index + p[index]] == s_pr[index - p[index]]:
                p[index] += 1
            if index + p[index] > mx:
                mx = index + p[index]
                id = index
            index += 1
            if index >= len(s_pr) - 1:
                break
        maxn, pos = 0, -1
        for index in range(len(s_pr)):
            if maxn < p[index] - 1 or\
               (maxn == p[index] - 1 and s_pr[index] == '#'):
                maxn = p[index] - 1
                pos = index
        return ''.join(s_pr[pos - maxn:pos + maxn + 1].split('#'))


if __name__ == '__main__':
    solution = Solution()
    print solution.longestPalindrome('abb')
