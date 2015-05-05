# -*- coding: utf-8 -*-


class Solution:
    # @param {string[]} words
    # @param {integer} maxWidth
    # @return {string[]}
    def fullJustify(self, words, maxWidth):
        ret = []
        cnt, beg = 0, 0
        for i in range(len(words)):
            if cnt + len(words[i]) <= maxWidth:
                cnt += len(words[i]) + 1
            else:
                sum = 0
                for j in range(beg, i):
                    sum += len(words[j])
                if i - 1 - beg:
                    avg = (maxWidth - sum) / (i - 1 - beg)
                else:
                    avg = 0
                left = (maxWidth - sum) - avg * (i - 1 - beg)
                if i - 1 - beg:
                    for j in range(left):
                        words[beg + j] += ' '
                else:
                     words[beg] += ' ' * left
                ret.append((' ' * avg).join(words[beg:i]))
                beg, cnt = i, len(words[i]) + 1
        sum, i = 0, len(words)
        for j in range(beg, i):
            sum += len(words[j])
        if i - 1 - beg:
            avg = 1
        else:
            avg = 0
        left = (maxWidth - sum) - avg * (i - 1 - beg)
        ret.append((' ' * avg).join(words[beg:i]) + ' ' * left)
        return ret


if __name__ == '__main__':
    solution = Solution()
    print solution.fullJustify(["This", "is", "an", "example",
                                "of", "text", "justification."], 14)
    print solution.fullJustify(["What", "must", "be",
                                "shall", "be."], 12)
