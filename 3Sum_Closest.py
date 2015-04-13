# -*- coding: utf-8 -*-


class Solution:
    # @return an integer
    def threeSumClosest(self, nums, target):
        minn, tag = -1, False
        nums = sorted(nums)
        for index in range(len(nums) - 2):
            l, r = index + 1, len(nums) - 1
            while l < r:
                sum = nums[l] + nums[r] + nums[index]
                if tag is False or abs(sum - target) < abs(minn - target):
                    tag, minn = True, sum
                if sum < target:
                    l += 1
                elif sum > target:
                    r -= 1
                else:
                    return sum
        return minn


if __name__ == '__main__':
    solution = Solution()
    print solution.threeSumClosest([-1, 2, 1, -4], 1)
