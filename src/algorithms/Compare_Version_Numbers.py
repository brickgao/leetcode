# -*- coding: utf-8 -*-


class Solution:
    # @param {string} version1
    # @param {string} version2
    # @return {integer}
    def compareVersion(self, version1, version2):
        l1, l2 = version1.split('.'), version2.split('.')
        for i in range(min(len(l1), len(l2))):
            if int(l1[i]) > int(l2[i]):
                return 1
            elif int(l1[i]) < int(l2[i]):
                return -1
        if len(l1) > len(l2):
            for i in range(len(l2), len(l1)):
                if int(l1[i]) != 0:
                    return 1
            return 0
        elif len(l1) < len(l2):
            for i in range(len(l1), len(l2)):
                if int(l2[i]) != 0:
                    return -1
            return 0
        else:
            return 0


if __name__ == "__main__":
    solution = Solution()
    print solution.compareVersion("1", "0")
    print solution.compareVersion("1.1", "1")
    print solution.compareVersion("1.0", "1")
