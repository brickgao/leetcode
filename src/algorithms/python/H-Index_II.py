# -*- coding: utf-8 -*-


class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if citations == []:
            return 0
        l, r, result = 0, len(citations) - 1, 0
        while l < r - 1:
            mid = (l + r) >> 1
            if citations[len(citations) - mid - 1] > mid:
                l = mid
            else:
                r = mid
        if citations[len(citations) - l - 1] > l:
            result = l + 1
        if citations[len(citations) - r - 1] > r:
            result = r + 1
        return result


if __name__ == "__main__":
    solution = Solution()
    print solution.hIndex([3, 3, 4, 4, 6, 6, 8, 10])
