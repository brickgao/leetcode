# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        ret_node = ListNode(0)
        tmp = ret_node
        node1, node2 = l1, l2
        while node1 and node2:
            if node1.val > node2.val:
                tmp.next = node2
                node2 = node2.next
            else:
                tmp.next = node1
                node1 = node1.next
            tmp = tmp.next
        while node1:
            tmp.next = node1
            node1, tmp = node1.next, tmp.next
        while node2:
            tmp.next = node2
            node2, tmp = node2.next, tmp.next
        return ret_node.next


if __name__ == '__main__':
    solution = Solution()
    a, b = ListNode(1), ListNode(3)
    c, d = ListNode(2), ListNode(4)
    a.next, c.next = b, d
    ret = solution.mergeTwoLists(a, c)
    while ret:
        print ret.val
        ret = ret.next
