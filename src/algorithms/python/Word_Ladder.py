# -*- coding: utf-8 -*-

from Queue import Queue


class Solution:
    # @param beginWord, a string
    # @param endWord, a string
    # @param wordDict, a set<string>
    # @return an integer
    def ladderLength(self, beginWord, endWord, wordDict):
        if beginWord == endWord:
            return []
        alpha_list = [chr(ord('a') + i) for i in range(26)]
        wordDict.add(endWord)
        w_length = len(beginWord)
        vis = {beginWord: True}
        q = Queue()
        q.put((beginWord, 0))
        while not q.empty():
            top_word, top_cnt = q.get()
            for i in range(w_length):
                part1, part2 = top_word[:i], top_word[i + 1:]
                for ch in alpha_list:
                    if ch != top_word[i]:
                        tmp = part1 + ch + part2
                        if tmp in wordDict:
                            new_cnt = top_cnt + 1
                            if tmp == endWord:
                                return new_cnt + 1
                            else:
                                if tmp not in vis:
                                    vis[tmp] = new_cnt
                                    q.put((tmp, new_cnt))
        return 0


if __name__ == "__main__":
    solution = Solution()
    print solution.ladderLength(
        "hit", "cog", {"hot", "dot", "dog", "lot", "log"}
    )
