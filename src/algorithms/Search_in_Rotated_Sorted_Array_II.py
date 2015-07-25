# -*- coding: utf-8 -*-


class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        if A == []:
            return False
        now, pre = 1, A[0]
        for i in range(1, len(A)):
            if A[i] != pre:
                A[now] = A[i]
                now, pre = now + 1, A[i]
        l, r = 0, now - 1
        while l < r:
            mid = (l + r) >> 1
            if A[mid] == target:
                return True
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
        return False if A[l] != target else True


if __name__ == '__main__':
    solution = Solution()
    print solution.search([1, 3, 1, 1, 1], 3)
