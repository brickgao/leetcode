# -*- coding: utf-8 -*-


class Solution(object):
    def getSubMax(self, nums, k):
        result = []
        pre, length = 0, len(nums)
        for i in range(k - 1, -1, -1):
            _maxn, _pre = -1, -1
            for j in range(pre, length - i):
                if nums[j] > _maxn:
                    _maxn, _pre = nums[j], j
            if _maxn == -1:
                result += nums[pre:]
            else:
                result.append(_maxn)
                pre = _pre + 1
        return result

    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        m, n = len(nums1), len(nums2)
        result = []
        for kk in range(max(k - n, 0), min(k, m) + 1):
            l1, l2 = self.getSubMax(nums1, kk), self.getSubMax(nums2, k - kk)
            result = max([max(l1, l2).pop(0) for _ in l1 + l2], result)
        return result


if __name__ == "__main__":
    solution = Solution()
    print solution.maxNumber([3, 4, 6, 5], [9, 1, 2, 5, 8, 3], 5)
    print solution.maxNumber([6, 7], [6, 0, 4], 5)
    print solution.maxNumber([3, 9], [8, 9], 3)
