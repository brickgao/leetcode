# -*- coding: utf-8 -*-


class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, nums):
        num_dict, ret_l = {}, []
        for num in nums:
            if num not in num_dict:
                num_dict[num] = 1
            else:
                num_dict[num] += 1
        nums = sorted(num_dict.keys())
        num_len = len(nums)
        for i in range(num_len):
            for j in range(i, num_len):
                num1, num2 = nums[i], nums[j]
                if i == j and num_dict[num1] < 2:
                    continue
                num3 = 0 - num1 - num2
                if num3 < num2:
                    continue
                if num3 != num1 and num3 != num2:
                    if num3 in num_dict:
                        ret_l.append(sorted([num1, num2, num3]))
                elif num3 == num1 and num3 == num2:
                    if num_dict[num3] >= 3:
                        ret_l.append([num1, num2, num3])
                else:
                    if num3 in num_dict and num_dict[num3] >= 2:
                        ret_l.append(sorted([num1, num2, num3]))
        return ret_l


if __name__ == '__main__':
    solution = Solution()
    print solution.threeSum([-1, 0, 1, 2, -1, -4])
    print solution.threeSum([0, 0])
