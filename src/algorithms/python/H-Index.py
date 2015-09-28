# -*- coding: utf-8 -*-


class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort()
        for index in range(len(citations)):
            tmp = len(citations) - index
            if tmp <= citations[index]:
                if index == 0 or tmp >= citations[index - 1]:
                    return tmp
        return 0


if __name__ == "__main__":
    solution = Solution()
    print solution.hIndex([3, 0, 6, 1, 5])
    print solution.hIndex([100])
