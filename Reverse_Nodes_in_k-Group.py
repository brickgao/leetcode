# -*- coding:utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
        if k <= 1:
            return head
        elif head is None:
            return None
        else:
            node = head
            while node:
                node_l = []
                for i in range(k):
                    if not node:
                        break
                    node_l.append(node)
                    node = node.next
                if len(node_l) != k:
                    break
                if head is node_l[0]:
                    head = node_l[-1]
                end_nxt = node_l[k - 1].next
                for i in range(1, k):
                    node_l[i].next = node_l[(i - 1) % k]
                tmp, tag = node, True
                for i in range(k - 1):
                    if tmp is None:
                        tag = False
                        break
                    tmp = tmp.next
                node_l[0].next = tmp if tmp and tag else end_nxt
            return head


if __name__ == '__main__':
    solution = Solution()
    a, b = ListNode(1), ListNode(2)
    c, d = ListNode(3), ListNode(4)
    e, f = ListNode(5), ListNode(6)
    a.next, b.next = b, c
    c.next, d.next = d, e
    e.next = f
    node = solution.reverseKGroup(a, 3)
    while node:
        print node.val
        node = node.next
