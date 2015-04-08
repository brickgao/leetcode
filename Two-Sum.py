# -*- coding: utf-8 -*-


class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        num_dict = {}
        for index, s_num in enumerate(num):
            if s_num not in num_dict:
                num_dict[s_num] = [index]
            else:
                num_dict[s_num].append(index)
        for index, s_num in enumerate(num):
            if s_num == target - s_num:
                if len(num_dict[s_num]) == 2:
                    return (num_dict[s_num][0] + 1,
                            num_dict[s_num][1] + 1)
            else:
                if target - s_num in num_dict:
                    return (index + 1,
                            num_dict[target - s_num][0] + 1)


if __name__ == '__main__':
    solution = Solution()
    print solution.twoSum([-1, -2, -3, -4, -5], -8)
