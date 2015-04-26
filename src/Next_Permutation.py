# -*- coding: utf-8 -*-


class Solution:
    # @param num, a list of integer
    # @return nothing (void), do not return anything,
    # modify num in-place instead.
    def nextPermutation(self, num):
        pos = -1
        for i in range(len(num) - 1, 0, -1):
            if num[i] > num[i - 1]:
                pos = i - 1
                break
        if pos == -1:
            num.sort()
        else:
            pos_num = num[pos]
            num[pos + 1:] = sorted(num[pos + 1:])
            for i in range(pos + 1, len(num)):
                if num[i] > pos_num:
                    num[pos], num[i] = num[i], pos_num
                    break


if __name__ == '__main__':
    solution = Solution()
    solution.nextPermutation([1, 2, 3])
    solution.nextPermutation([3, 2, 1])
    solution.nextPermutation([2, 1, 3])
    solution.nextPermutation([1, 3, 2])
