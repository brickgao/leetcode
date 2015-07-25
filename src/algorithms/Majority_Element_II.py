# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def majorityElement(self, nums):
        if nums == []:
            return []
        num1, num2 = -0xffffffff, -0xffffffff
        cnt1, cnt2 = 0, 0
        for num in nums:
            if cnt1 == 0 or num1 == num:
                num1, cnt1 = num, cnt1 + 1
            elif cnt2 == 0 or num2 == num:
                num2, cnt2 = num, cnt2 + 1
            else:
                cnt1, cnt2 = cnt1 - 1, cnt2 - 1
        cnt1, cnt2 = 0, 0
        for num in nums:
            if num == num1:
                cnt1 += 1
            elif num == num2:
                cnt2 += 1
        ret = []
        if num1 != -0xffffffff and cnt1 > len(nums) / 3.0:
            ret.append(num1)
        if num2 != -0xffffffff and cnt2 > len(nums) / 3.0:
            ret.append(num2)
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.majorityElement([1, 2, 3])
