# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} height
    # @return {integer}
    def trap(self, height):
        if height == []:
            return 0
        l_rec = [0 for i in range(len(height))]
        r_rec = [0 for i in range(len(height))]
        l_rec[0], r_rec[len(height) - 1] = height[0], height[len(height) - 1]
        for i in range(1, len(l_rec)):
            l_rec[i] = max(l_rec[i - 1], height[i])
        for i in range(len(r_rec) - 2, -1, -1):
            r_rec[i] = max(r_rec[i + 1], height[i])
        ret = 0
        for i in range(len(height)):
            ret += min(l_rec[i], r_rec[i]) - height[i]
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
    print solution.trap([2, 0, 2])
    print solution.trap([5, 4, 1, 2])
    print solution.trap([2, 1, 0, 2])
    print solution.trap([])
