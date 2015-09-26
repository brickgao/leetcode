# -*- coding: utf-8 -*-


class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return 'Zero'
        result = []
        rec = ['', 'Thousand', 'Million', 'Billion']
        num2words = {
            1: 'One',
            2: 'Two',
            3: 'Three',
            4: 'Four',
            5: 'Five',
            6: 'Six',
            7: 'Seven',
            8: 'Eight',
            9: 'Nine',
            10: 'Ten',
            11: 'Eleven',
            12: 'Twelve',
            13: 'Thirteen',
            14: 'Fourteen',
            15: 'Fifteen',
            16: 'Sixteen',
            17: 'Seventeen',
            18: 'Eighteen',
            19: 'Nineteen',
            20: 'Twenty',
            30: 'Thirty',
            40: 'Forty',
            50: 'Fifty',
            60: 'Sixty',
            70: 'Seventy',
            80: 'Eighty',
            90: 'Ninety',
            100: 'Hundred'
        }
        cnt = 0
        while num:
            tmp_l = []
            left = num % 1000
            if left >= 100:
                tmp_l.append(num2words[left // 100])
                tmp_l.append(num2words[100])
                left %= 100
            if left <= 20:
                if left > 0:
                    tmp_l.append(num2words[left])
            else:
                if left >= 10:
                    tmp_l.append(num2words[left // 10 * 10])
                    left %= 10
                if left > 0:
                    tmp_l.append(num2words[left])
            if cnt != 0 and tmp_l != []:
                tmp_l.append(rec[cnt])
            num /= 1000
            result = tmp_l + result
            cnt += 1
        return ' '.join(result)


if __name__ == "__main__":
    solution = Solution()
    print solution.numberToWords(30)
    print solution.numberToWords(100)
    print solution.numberToWords(123)
    print solution.numberToWords(12345)
    print solution.numberToWords(1234567)
