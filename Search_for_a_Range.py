# -*- coding: utf-8 -*-


class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        l, r, fd = 0, len(A) - 1, -1
        while l < r:
            mid = (l + r) >> 1
            if A[mid] == target:
                fd = mid
                break
            elif A[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        if fd == -1:
            fd = l if A[l] == target else -1
        if fd == -1:
            return [-1, -1]
        else:
            l_bound, r_bound = -1, -1
            l, r = 0, fd
            while l < r:
                mid = (l + r) >> 1
                if A[mid] == target and (mid == 0 or
                                         A[mid - 1] != target):
                    l_bound = mid
                    break
                elif A[mid] < target:
                    l = mid + 1
                else:
                    r = mid - 1
            if A[l] == target and (l == 0 or A[l - 1] != target):
                l_bound = l
            l, r = fd, len(A) - 1
            while l < r:
                mid = (l + r) >> 1
                if A[mid] == target and (mid == len(A) - 1 or
                                         A[mid + 1] != target):
                    r_bound = mid
                    break
                elif A[mid] > target:
                    r = mid - 1
                else:
                    l = mid + 1
            if A[l] == target and (l == len(A) - 1 or A[l + 1] != target):
                r_bound = l
            return [l_bound, r_bound]


if __name__ == '__main__':
    solution = Solution()
    print solution.searchRange([5, 7, 7, 8, 8, 10], 8)
    print solution.searchRange([1], 1)
