# -*- coding: utf-8 -*-


class Solution:
    def get_rec_area(self, p1, p2):
        return abs((p1[0] - p2[0]) * (p1[1] - p2[1]))

    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        area = self.get_rec_area((A, B), (C, D))
        area += self.get_rec_area((E, F), (G, H))
        if not (E >= C or G <= A or B >= H or D <= F):
            area -= self.get_rec_area((max(E, A), max(B, F)),
                                      (min(C, G), min(D, H)))
        return area


if __name__ == "__main__":
    solution = Solution()
    print solution.computeArea(-3, 0, 3, 4, 0, -1, 9, 2)
