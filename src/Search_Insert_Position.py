# -*- coding: utf-8 -*-


class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        l, r = 0, len(A) - 1
        while l < r:
            mid = (l + r) >> 1
            if A[mid] == target:
                return mid
            elif A[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        return l + 1 if A[l] < target else l


if __name__ == '__main__':
    solution = Solution()
    print solution.searchInsert([1, 3, 5, 6], 5)
    print solution.searchInsert([1, 3, 5, 6], 2)
    print solution.searchInsert([1, 3, 5, 6], 7)
    print solution.searchInsert([1, 3, 5, 6], 0)
