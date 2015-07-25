# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @return {integer}
    def calculate(self, s):
        t_s, tag = s + "+", False
        tmp, ret = 1, 0
        pre1, pre2 = "", ""
        now = ""
        for i in range(len(t_s)):
            if t_s[i] == "*" or t_s[i] == "/":
                tag = True
                if pre1 == "/":
                    tmp /= int(now)
                else:
                    tmp *= int(now)
                pre1, now = t_s[i], ""
            elif t_s[i] == "+" or t_s[i] == "-":
                if tag:
                    if pre1 == "/":
                        tmp /= int(now)
                    else:
                        tmp *= int(now)
                    n_now = tmp
                    tag, tmp = False, 1
                    pre1 = ""
                else:
                    n_now = int(now)
                if pre2 == "-":
                    ret -= n_now
                else:
                    ret += n_now
                pre2, now = t_s[i], ""
            else:
                now += t_s[i]
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.calculate("3+2*2")
    print solution.calculate("3/2")
    print solution.calculate("3+5/2")
