# -*- coding: utf-8 -*-


class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        l, r = 0, len(A) - 1
        while l < r:
            mid = (l + r) >> 1
            if A[mid] == target:
                return mid
            elif A[mid] > target:
                if A[mid] > A[r] and target < A[l]:
                    l = mid + 1
                else:
                    r = mid - 1
            else:
                if A[mid] < A[l] and target > A[r]:
                    r = mid - 1
                else:
                    l = mid + 1
        return -1 if A[l] != target else l


if __name__ == '__main__':
    solution = Solution()
    print solution.search([4, 5, 6, 7, 0, 1, 2], 0)
    print solution.search([1, 3], 3)
    print solution.search([1], 0)
    print solution.search([3, 5, 1], 3)
