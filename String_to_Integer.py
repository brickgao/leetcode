# -*- coding: utf-8 -*-

import re


class Solution:
    # @return an integer
    def atoi(self, str):
        pattern = re.compile(r'^\s*[+|-]?\d+\s*$')
        upper_bound, lower_bound = (1 << 31) - 1, - (1 << 31)
        for i in range(len(str), -1, -1):
            if not pattern.match(str[:i]):
                continue
            num = int(str[:i])
            if num > upper_bound:
                return upper_bound
            elif num < lower_bound:
                return lower_bound
            else:
                return num
        return 0


if __name__ == '__main__':
    solution = Solution()
    print solution.atoi('1a')
