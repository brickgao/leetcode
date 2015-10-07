# -*- coding: utf-8 -*-


class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        l = str.split()
        d_pos, d_neg = {}, {}
        if len(l) != len(pattern):
            return False
        for index in range(len(pattern)):
            if pattern[index] in d_pos or l[index] in d_neg:
                if pattern[index] not in d_pos or l[index] not in d_neg:
                    return False
                if (
                        d_pos[pattern[index]] != l[index] or
                        d_neg[l[index]] != pattern[index]
                   ):
                    return False
            d_pos[pattern[index]] = l[index]
            d_neg[l[index]] = pattern[index]
        return True


if __name__ == "__main__":
    solution = Solution()
    print solution.wordPattern("abba", "dog cat cat dog")
    print solution.wordPattern("abba", "dog cat cat fish")
    print solution.wordPattern("aaaa", "dog cat cat dog")
    print solution.wordPattern("abba", "dog dog dog dog")
