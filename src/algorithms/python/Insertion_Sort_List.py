# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def insertionSortList(self, head):
        if not head:
            return head
        _ = ListNode(-0xffffffffff)
        cur, pre, end = head, _, _
        while cur:
            nxt = cur.next
            if cur.val < end.val:
                while pre.next and pre.next.val < cur.val:
                    pre = pre.next
                cur.next = pre.next
                pre.next = cur
                pre = _
            else:
                cur.next = end.next
                end.next = cur
                end = cur
            cur = nxt
        return _.next


if __name__ == "__main__":
    solution = Solution()
    a, b, c, d = ListNode(4), ListNode(3), ListNode(2), ListNode(1)
    a.next, b.next, c.next = b, c, d
    node = solution.insertionSortList(a)
    while node:
        print node.val
        node = node.next
