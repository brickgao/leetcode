# -*- coding: utf-8 -*-


class Solution:

    def getKthNumber(self, A, B, k):
        m, n = len(A), len(B)
        if m > n:
            return self.getKthNumber(B, A, k)
        if not m:
            return B[k - 1]
        if k == 1:
            return min(A[0], B[0])
        pa = min(k / 2, m)
        pb = k - pa
        if A[pa - 1] < B[pb - 1]:
            return self.getKthNumber(A[pa:], B, k - pa)
        elif A[pa - 1] > B[pb - 1]:
            return self.getKthNumber(A, B[pb:], k - pb)
        else:
            return A[pa - 1]

    # @return a float
    def findMedianSortedArrays(self, A, B):
        m, n = len(A), len(B)
        if (m + n) % 2:
            return float(self.getKthNumber(A, B,
                                           (m + n) / 2 + 1))
        else:
            return (self.getKthNumber(A, B, (m + n) / 2 + 1) +
                    self.getKthNumber(A, B, (m + n) / 2)) / 2.


if __name__ == '__main__':
    solution = Solution()
    print solution.findMedianSortedArrays([], [1])
