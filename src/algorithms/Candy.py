# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} ratings
    # @return {integer}
    def candy(self, ratings):
        pre = 0
        l = [1 for i in range(len(ratings))]
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                l[i] = l[i - 1] + 1
                for j in range(i - 1, pre, -1):
                    l[j - 1] = max(l[j] + 1, l[j - 1])
                pre = i
            elif ratings[i] == ratings[i - 1]:
                for j in range(i - 1, pre, -1):
                    l[j - 1] = max(l[j] + 1, l[j - 1])
                pre = i
        for i in range(len(ratings) - 1, pre, -1):
            l[i - 1] = max(l[i] + 1, l[i - 1])
        return sum(l)


if __name__ == "__main__":
    solution = Solution()
    print solution.candy([1, 2, 3])
    print solution.candy([1, 0, 2])
    print solution.candy([1, 2, 2])
    print solution.candy([4, 2, 3, 4, 1])
