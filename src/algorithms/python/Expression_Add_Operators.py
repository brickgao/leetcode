# -*- coding: utf-8 -*-


class Solution(object):
    def is_valid(self, num):
        return False if num.startswith("0") and num != "0" else True

    def dfs(self, now, target, mulexpr="", mulval=1):
        result = []
        if self.is_valid(now) and int(now) * mulval == target:
            result.append(now + mulexpr)
        for i in range(len(now) - 1):
            left, right = now[:i + 1], now[i + 1:]
            if self.is_valid(right):
                rightexpr, rightval = right + mulexpr, int(right) * mulval
                for j in self.dfs(left, target - rightval):
                    result.append(j + '+' + rightexpr)
                for j in self.dfs(left, target + rightval):
                    result.append(j + '-' + rightexpr)
                for j in self.dfs(left, target, '*' + rightexpr, rightval):
                    result.append(j)
        return result

    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        if num == "":
            return []
        return self.dfs(num, target)


if __name__ == "__main__":
    solution = Solution()
    print solution.addOperators("123", 6)
    print solution.addOperators("232", 8)
    print solution.addOperators("105", 5)
    print solution.addOperators("00", 0)
    print solution.addOperators("3456237490", 9191)
