# -*- coding: utf-8 -*-

from collections import Counter


class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        ch_cnt_dict, st, vis = Counter(s), [], [False for i in range(26)]
        for ch in s:
            if not vis[ord(ch) - ord('a')]:
                while (len(st) != 0 and
                       ord(ch) < ord(st[-1]) and
                       ch_cnt_dict[st[-1]]) > 0:
                    vis[ord(st[-1]) - ord('a')] = False
                    st.pop()
                st.append(ch)
                vis[ord(ch) - ord('a')] = True
            ch_cnt_dict[ch] -= 1
        return "".join(st)


if __name__ == "__main__":
    solution = Solution()
    print solution.removeDuplicateLetters("bcabc")
    print solution.removeDuplicateLetters("cbacdcbc")
