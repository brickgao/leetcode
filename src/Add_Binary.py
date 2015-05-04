# -*- coding: utf-8 -*-


class Solution:
    # @param {string} a
    # @param {string} b
    # @return {string}
    def addBinary(self, a, b):
        num_a, num_b = int(a, 2), int(b, 2)
        return bin(num_a + num_b)[2:]


if __name__ == '__main__':
    solution = Solution()
    print solution.addBinary('11', '1')
