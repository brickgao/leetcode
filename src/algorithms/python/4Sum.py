# -*- coding: utf-8 -*-


class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, nums, target):
        ret_l = []
        nums.sort()
        len_nums = len(nums)
        for i in range(len_nums - 3):
            if nums[i] > target / 4.:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len_nums - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                if nums[j] > (target - nums[i]) / 3.:
                    break
                l, r = j + 1, len_nums - 1
                new_target = target - (nums[i] + nums[j])
                while l < r:
                    sum = nums[l] + nums[r]
                    if sum == new_target:
                        ret_l.append([nums[i], nums[j],
                                      nums[l], nums[r]])
                        l += 1
                        while l < len_nums and nums[l] == nums[l - 1]:
                            l += 1
                        while r > l and nums[r - 1] == nums[r]:
                            r -= 1
                    elif sum > new_target:
                        r -= 1
                    else:
                        l += 1
        return ret_l


if __name__ == '__main__':
    solution = Solution()
    print solution.fourSum([-3, -2, -1, 0, 0, 1, 2, 3], 0)
    print solution.fourSum([0, 0, 0, 0], 0)
