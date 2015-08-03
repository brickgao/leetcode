# -*- coding: utf-8 -*-


class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        _l = s.split(" ")[::-1]
        l = []
        for s in _l:
            if s == "" or s.startswith(" "):
                continue
            l.append(s)
        return " ".join(l)


if __name__ == "__main__":
    solution = Solution()
    print solution.reverseWords("the sky is blue")
