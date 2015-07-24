# -*- coding: utf-8 -*-

import heapq


class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer[]}
    def maxSlidingWindow(self, nums, k):
        if nums == []:
            return []
        nums = map(lambda x: -x, nums)
        lazy_del = {}
        heap, ret = nums[:k], []
        heapq.heapify(heap)
        ret.append(-heap[0])
        for i in range(k, len(nums)):
            if nums[i - k] == heap[0]:
                heapq.heappop(heap)
            else:
                if nums[i - k] not in lazy_del:
                    lazy_del[nums[i - k]] = 1
                else:
                    lazy_del[nums[i - k]] += 1
            while len(heap) != 0 and heap[0] in lazy_del:
                lazy_del[heap[0]] -= 1
                if lazy_del[heap[0]] <= 0:
                    del lazy_del[heap[0]]
                heapq.heappop(heap)
            heapq.heappush(heap, nums[i])
            ret.append(-heap[0])
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3)
    print solution.maxSlidingWindow([9, 10, 9, -7, -4, -8, 2, -6], 5)
    print solution.maxSlidingWindow([1, -1], 1)
