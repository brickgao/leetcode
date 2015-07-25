# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @param {integer} x
    # @return {ListNode}
    def partition(self, head, x):
        node, pre_node, lg_node = head, None, None
        tag = False
        while node:
            nxt = node.next
            if node.val >= x:
                if not lg_node:
                    lg_node = node
                    if pre_node:
                        tag = True
                    else:
                        pre_node = node
                else:
                    lg_node.next = node
                    lg_node = node
            else:
                if lg_node:
                    if tag:
                        tmp = pre_node.next
                        pre_node.next = node
                        node.next = tmp
                        pre_node = node
                    else:
                        node.next = pre_node
                        head = pre_node = node
                        tag = True
            if not lg_node:
                pre_node = node
            node = nxt
        if lg_node:
            lg_node.next = None
        return head


if __name__ == "__main__":
    solution = Solution()
    a, b = ListNode(1), ListNode(4)
    c, d = ListNode(3), ListNode(2)
    e, f = ListNode(5), ListNode(2)
    a.next, b.next = b, c
    c.next, d.next = d, e
    e.next = f
    node = solution.partition(a, 3)
    while node:
        print node.val
        node = node.next
    print '-' * 15
    a, b = ListNode(2), ListNode(1)
    a.next = b
    node = solution.partition(a, 2)
    while node:
        print node.val
        node = node.next
