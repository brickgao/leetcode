# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, now, s):
        if len(now) == 4 and s != "":
            return
        if len(now) == 4 and s == "":
            s_now = map(str, now)
            self.ret.append(".".join(s_now))
            return
        if float(len(s)) / (4 - len(now)) > 3.0:
            return
        for i in range(1, min(len(s) + 1, 4)):
            num = int(s[:i])
            if str(num) != s[:i]:
                continue
            if num <= 255:
                tmp = now + (num, )
                if tmp not in self.vis:
                    self.vis[tmp] = True
                    self.dfs(tmp, s[i:])

    # @param {string} s
    # @return {string[]}
    def restoreIpAddresses(self, s):
        self.vis = {}
        self.ret = []
        self.dfs((), s)
        return self.ret


if __name__ == "__main__":
    solution = Solution()
    print solution.restoreIpAddresses("25525511135")
    print solution.restoreIpAddresses("010010")
