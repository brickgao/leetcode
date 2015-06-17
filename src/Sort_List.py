# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def sortList(self, head):
        if not head:
            return head
        flag, length, cnt, n_head = False, 0, 1, ListNode(0)
        while True:
            node, cur = head, n_head
            while node:
                tmp1, tmp2 = node, None
                for i in range(cnt * 2):
                    if not flag:
                        length += 1
                    if not node:
                        break
                    if i == cnt:
                        tmp2 = node
                    pre = node
                    node = node.next
                node1, node2 = tmp1, tmp2
                while node1 != tmp2 and node2 != node:
                    if node1.val < node2.val:
                        cur.next = node1
                        cur = node1
                        node1 = node1.next
                    else:
                        cur.next = node2
                        cur = node2
                        node2 = node2.next
                while node1 != tmp2:
                    cur.next = node1
                    cur = node1
                    node1 = node1.next
                while node2 != node:
                    cur.next = node2
                    cur = node2
                    node2 = node2.next
                cur.next = None
            flag, head = True, n_head.next
            if flag and cnt * 2 >= length:
                return head
            cnt *= 2


if __name__ == "__main__":
    solution = Solution()
    l = [4, 3, 2, 1]
    l = map(lambda x: ListNode(x), l)
    for i in range(len(l) - 1):
        l[i].next = l[i + 1]
    node = solution.sortList(l[0])
    while node:
        print node.val
        node = node.next
