# -*- coding: utf-8 -*-


class Solution(object):
    def get_step(self, s):
        st = []
        for ch in s:
            if ch != '(' and ch != ')':
                continue
            if st != [] and st[-1] == '(' and ch == ')':
                st.pop()
            else:
                st.append(ch)
        return len(st)

    def dfs(self, s, step):
        for i in xrange(len(s)):
            if s[i] != '(' and s[i] != ')':
                continue
            new_s = s[:i] + s[i + 1:]
            if new_s in self.vis:
                continue
            self.vis.add(new_s)
            new_step = self.get_step(new_s)
            if new_step == 0:
                self.ret.append(new_s)
            elif new_step < step:
                self.dfs(new_s, new_step)

    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if self.get_step(s) == 0:
            return [s]
        else:
            self.ret, self.vis = [], set()
            self.dfs(s, self.get_step(s))
            return self.ret

if __name__ == "__main__":
    solution = Solution()
    print solution.removeInvalidParentheses("()())()")
    print solution.removeInvalidParentheses("(a)())()")
    print solution.removeInvalidParentheses(")(")
    print solution.removeInvalidParentheses(")))())((p((())a(())(")
