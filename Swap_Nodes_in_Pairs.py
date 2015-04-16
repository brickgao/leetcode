# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if head is None:
            return None
        l_p, c_p, h_nxt, cnt = None, head, head.next, 0
        while c_p:
            nxt_p = c_p.next
            if cnt % 2:
                if c_p.next and c_p.next.next:
                    l_p.next, c_p.next = c_p.next.next, l_p
                else:
                    l_p.next, c_p.next = c_p.next, l_p
                c_p = nxt_p
            else:
                l_p, c_p = c_p, nxt_p
            cnt += 1
        return h_nxt if h_nxt else head


if __name__ == '__main__':
    solution = Solution()
    a, b = ListNode(1), ListNode(2)
    c, d = ListNode(3), ListNode(4)
    a.next, b.next, c.next = b, c, d
    node = solution.swapPairs(a)
    while node:
        print node.val
        node = node.next
