# -*- coding: utf-8 -*-


class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        ch_dict = {}
        lsb_len, str_len = 0, 0
        for index, ch in enumerate(s):
            if ch not in ch_dict:
                ch_dict[ch] = index
                str_len += 1
            else:
                if index - str_len <= ch_dict[ch]:
                    str_len = index - ch_dict[ch]
                else:
                    str_len += 1
                ch_dict[ch] = index
            lsb_len = max(lsb_len, str_len)
        return lsb_len


if __name__ == '__main__':
    solution = Solution()
    print solution.lengthOfLongestSubstring('tmmzuxt')
