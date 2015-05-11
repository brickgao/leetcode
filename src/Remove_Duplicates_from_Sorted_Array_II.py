# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def removeDuplicates(self, nums):
        if nums == []:
            return 0
        n_len, now = 0, 0
        tmp, pre = 0, nums[0]
        for num in nums:
            if pre == num:
                tmp += 1
            else:
                cnt = min(tmp, 2)
                n_len += cnt
                for j in range(cnt):
                    nums[now] = pre
                    now += 1
                tmp, pre = 1, num
        cnt = min(tmp, 2)
        n_len += cnt
        for j in range(cnt):
            nums[now] = nums[-1]
            now += 1
        return n_len


if __name__ == '__main__':
    solution = Solution()
    print solution.removeDuplicates([1, 1, 1, 2, 2, 3])
    print solution.removeDuplicates([1])
    print solution.removeDuplicates([1, 2])
