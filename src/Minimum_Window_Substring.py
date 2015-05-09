# -*- coding: utf-8 -*-


class Solution:
    # @param {string} s
    # @param {string} t
    # @return {string}
    def minWindow(self, s, t):
        s_rec, t_rec = {}, {}
        st, i, ret = 0, 0, None
        for ch in t:
            if ch not in s_rec:
                s_rec[ch] = 0
            if ch not in t_rec:
                t_rec[ch] = 1
            else:
                t_rec[ch] += 1
        while st < len(s) and i < len(s):
            if s[i] in s_rec:
                s_rec[s[i]] += 1
            tag = True
            for key in t_rec:
                if s_rec[key] < t_rec[key]:
                    tag = False
                    break
            if tag:
                while (s[st] not in t_rec or
                       s_rec[s[st]] > t_rec[s[st]]):
                    if (s[st] in s_rec and
                       s_rec[s[st]] > t_rec[s[st]]):
                        s_rec[s[st]] -= 1
                    st += 1
                if ret:
                    if ret[1] - ret[0] > i + 1 - st:
                        ret = (st, i + 1)
                else:
                    ret = (st, i + 1)
            i += 1
        return s[ret[0]:ret[1]] if ret else ""


if __name__ == '__main__':
    solution = Solution()
    print solution.minWindow('ADOBECODEBANC', 'ABC')
