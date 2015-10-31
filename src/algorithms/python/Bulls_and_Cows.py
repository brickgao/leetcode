# -*- coding: utf-8 -*-

from collections import Counter


class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bull_cnt, cow_cnt = 0, 0
        secret_counter = Counter(secret)
        for index in range(len(secret)):
            if (guess[index] in secret_counter and
                    secret_counter[guess[index]] > 0 and
                    secret[index] == guess[index]):
                bull_cnt += 1
                secret_counter[guess[index]] -= 1
        for index in range(len(secret)):
            if (guess[index] in secret_counter and
                    secret_counter[guess[index]] > 0 and
                    secret[index] != guess[index]):
                cow_cnt += 1
                secret_counter[guess[index]] -= 1
        return str(bull_cnt) + "A" + str(cow_cnt) + "B"


if __name__ == "__main__":
    solution = Solution()
    print solution.getHint("1807", "7810")
    print solution.getHint("0", "1")
    print solution.getHint("1122", "1222")
