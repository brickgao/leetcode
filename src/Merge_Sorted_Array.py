# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums1
    # @param {integer} m
    # @param {integer[]} nums2
    # @param {integer} n
    # @return {void} Do not return anything, modify nums1 in-place instead.
    def merge(self, nums1, m, nums2, n):
        i, j = 0, 0
        while i < m and j < n:
            if nums1[i] >= nums2[j]:
                m += 1
                for k in range(m - 1, i, -1):
                    nums1[k] = nums1[k - 1]
                nums1[i] = nums2[j]
                i, j = i + 1, j + 1
            else:
                i += 1
        if j != n:
            nums1[i:] = nums2[j:]
        print nums1


if __name__ == "__main__":
    solution = Solution()
    solution.merge([1, 3, 4, 0, 0], 3, [2, 5], 2)
    solution.merge([1, 2, 3, 0, 0], 3, [4, 5], 2)
    solution.merge([3, 4, 5, 0, 0], 3, [1, 2], 2)
    solution.merge([0], 0, [1], 1)
