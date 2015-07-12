# -*- coding: utf-8 -*-

import heapq


class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer}
    def findKthLargest(self, nums, k):
        heap = []
        for num in nums:
            if len(heap) < k:
                heapq.heappush(heap, num)
            else:
                if heap[0] < num:
                    heapq.heappop(heap)
                    heapq.heappush(heap, num)
        return heapq.heappop(heap)


if __name__ == "__main__":
    solution = Solution()
    print solution.findKthLargest([3, 2, 1, 5, 6, 4], 2)
