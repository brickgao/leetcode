# -*- coding: utf-8 -*-


class Solution:
    # @param {integer[]} gas
    # @param {integer[]} cost
    # @return {integer}
    def canCompleteCircuit(self, gas, cost):
        l = [0 for i in range(len(gas))]
        for i in range(len(gas)):
            l[i] = gas[i] - cost[i]
        tmp, ret = 0, 0
        for i in range(len(gas)):
            tmp += l[i]
            if tmp < 0:
                ret, tmp = (i + 1) % len(gas), 0
        tmp = 0
        for i in range(len(gas)):
            tmp += l[(i + ret) % len(gas)]
            if tmp < 0:
                return -1
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.canCompleteCircuit([6, 1, 4, 3, 5], [3, 8, 2, 4, 2])
