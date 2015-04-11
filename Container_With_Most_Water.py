# -*- coding: utf-8 -*-


class Solution:
    # @return an integer
    def maxArea(self, height):
        if len(height) <= 1:
            return 0
        container_size = 0
        l, r = 0, len(height) - 1
        while l < r:
            if height[l] > height[r]:
                container_size = max(container_size,
                                     height[r] * (r - l))
                r -= 1
            else:
                container_size = max(container_size,
                                     height[l] * (r - l))
                l += 1
        return container_size


if __name__ == '__main__':
    solution = Solution()
    print solution.maxArea([1, 2, 3, 4])
