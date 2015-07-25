# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def deleteDuplicates(self, head):
        if head is None:
            return None
        if head.next is None:
            return head
        while True:
            cnt = 1
            while head.next and head.val == head.next.val:
                cnt += 1
                head = head.next
            if cnt > 1:
                head = head.next
            if head is None:
                return None
            if head.next is None or head.val != head.next.val:
                break
        node, pre = head.next, head
        if node:
            while True:
                cnt = 1
                while node.next and node.val == node.next.val:
                    cnt += 1
                    node = node.next
                if cnt == 1:
                    pre.next = node
                    pre = node
                node = node.next
                if not node or not node.next:
                    break
            pre.next = node
        return head


if __name__ == '__main__':
    solution = Solution()
    a, b = ListNode(1), ListNode(1)
    c, d = ListNode(1), ListNode(1)
    e = ListNode(2)
    a.next, b.next = b, c
    c.next, d.next = d, e
    node = solution.deleteDuplicates(a)
    while node:
        print node.val
        node = node.next
    print '----------------'
    a, b = ListNode(1), ListNode(2)
    c, d = ListNode(3), ListNode(3)
    e, f = ListNode(4), ListNode(4)
    g = ListNode(5)
    a.next, b.next = b, c
    c.next, d.next = d, e
    e.next, f.next = f, g
    node = solution.deleteDuplicates(a)
    while node:
        print node.val
        node = node.next
