# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        ret = 0
        for i in range(32):
            cnt = 0
            for num in nums:
                cnt += 1 if abs(num) & (1 << i) else 0
            cnt %= 3
            ret += (cnt << i)
        cnt = 0
        for num in nums:
            if num == ret:
                cnt += 1
        return ret if cnt == 1 else -ret


if __name__ == "__main__":
    solution = Solution()
    print solution.singleNumber([1, 1, 1, 2, 3, 2, 2])
    print solution.singleNumber([-2, -2, 1, 1, -3, 1, -3, -3, -4, -2])
