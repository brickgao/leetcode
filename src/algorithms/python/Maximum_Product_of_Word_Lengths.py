# -*- coding: utf-8 -*-


class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        nums = []
        n, maxn = len(words), 0
        for word in words:
            num = 0
            for ch in word:
                num |= (1 << (ord(ch) - ord('a')))
            nums.append(num)
        for i in range(n):
            for j in range(i + 1, n):
                if (nums[i] & nums[j]) == 0:
                    maxn = max(maxn, len(words[i]) * len(words[j]))
        return maxn


if __name__ == "__main__":
    solution = Solution()
    print solution.maxProduct(["abcw", "baz", "foo", "bar", "xtfn", "abcdef"])
