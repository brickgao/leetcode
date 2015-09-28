# -*- coding: utf-8 -*-

from math import sqrt
from Queue import Queue


class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        q = Queue()
        visited = set()
        q.put((n, 0))
        while not q.empty():
            front = q.get()
            upper = int(sqrt(front[0])) + 1
            for i in range(1, upper):
                new_num = front[0] - i * i
                if new_num == 0:
                    return front[1] + 1
                if new_num not in visited:
                    visited.add(new_num)
                    q.put((new_num, front[1] + 1))


if __name__ == "__main__":
    solution = Solution()
    print solution.numSquares(12)
    print solution.numSquares(13)
    print solution.numSquares(9975)
