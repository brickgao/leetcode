# -*- coding: utf-8 -*-

from Queue import Queue


class Solution:
    def dfs(self, node):
        self.tmp_l.append(node)
        if self.pre[node] == []:
            self.ret_l.append(map(
                lambda index: self.l_dict[index], 
                self.tmp_l[::-1]
            ))
        for pre_node in self.pre[node]:
            self.dfs(pre_node)
        self.tmp_l.pop()
        
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string
    def findLadders(self, start, end, dict):
        if start == end:
            return []
        self.w_length = len(start)
        q = Queue()
        self.ret_l, self.tmp_l = [], []
        self.l_dict = [start] + list(dict) + [end]
        l_length = len(self.l_dict)
        nxt = [[] for i in range(l_length)]
        self.pre = [[] for i in range(l_length)]
        vis = {0: 0}
        dict = {}
        for i in range(l_length):
            dict[self.l_dict[i]] = i
        alpha_list = [chr(ord('a') + i) for i in range(26)]
        end_index = l_length - 1
        for index in range(l_length):
            word = self.l_dict[index]
            for i in range(self.w_length):
                for ch in alpha_list:
                    if ch != word[i]:
                        tmp = word[:i] + ch + word[i + 1:]
                        if tmp in dict:
                            nxt[index].append(dict[tmp])
        cnt = l_length
        q.put((0, 0))
        while not q.empty():
            top_index, top_cnt = q.get()
            if top_cnt >= cnt:
                break
            for index in nxt[top_index]:
                new_cnt = top_cnt + 1
                if index == end_index:
                    cnt = new_cnt
                    self.pre[index].append(top_index)
                else:
                    if index not in vis:
                        vis[index] = new_cnt
                        self.pre[index].append(top_index)
                        q.put((index, new_cnt))
                    elif vis[index] == new_cnt:
                        self.pre[index].append(top_index)
        if self.pre[end_index] == []:
            return []
        else:
            self.dfs(end_index)
            return self.ret_l


if __name__ == "__main__":
    solution = Solution()
    print solution.findLadders(
        "hit", "cog", ["hot", "dot", "dog", "lot", "log"]
    )
