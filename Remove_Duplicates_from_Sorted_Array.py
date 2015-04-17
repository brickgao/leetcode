# -*- coding: utf-8 -*-


class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if A == []:
            return 0
        cnt = 1
        for i in range(1, len(A)):
            if A[i] != A[i - 1]:
                A[cnt] = A[i]
                cnt += 1
        return cnt


if __name__ == '__main__':
    solution = Solution()
    print solution.removeDuplicates([1, 1, 2])
