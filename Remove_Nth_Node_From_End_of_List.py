# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def remove_node(self, head, n):
        if head.next is None:
            self.cnt += 1
            return
        else:
            self.remove_node(head.next, n)
            if self.cnt == n:
                nxt = head.next
                head.next = nxt.next
                del nxt
            self.cnt += 1

    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        self.cnt = 0
        self.remove_node(head, n)
        if self.cnt == 1:
            return None
        elif n == self.cnt:
            return head.next
        else:
            return head


if __name__ == '__main__':
    solution = Solution()
    a, b = ListNode(1), ListNode(2)
    c, d = ListNode(3), ListNode(4)
    e = ListNode(5)
    a.next, b.next = b, c
    c.next, d.next = d, e
    head = solution.removeNthFromEnd(a, 5)
    while head:
        print head.val
        head = head.next
    a = ListNode(1)
    head = solution.removeNthFromEnd(a, 1)
    while head:
        print head.val
        head = head.next
