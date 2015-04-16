# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1, l2):
        if l1 is None and l2 is None:
            return None
        elif l1 is not None and l2 is None:
            return l1
        elif l2 is not None and l1 is None:
            return l2
        else:
            ret_node = l2 if l1.val > l2.val else l1
            if ret_node is l2:
                l2 = l2.next
            else:
                l1 = l1.next
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
        return ret_node

    # @param a list of ListNode
    # @return a ListNode
    def mergeKLists(self, lists):
        if lists == []:
            return None
        elif len(lists) == 2:
            return self.mergeTwoLists(*lists)
        elif len(lists) == 1:
            return lists[0]
        else:
            mid = len(lists) / 2
            merged_l = self.mergeKLists(lists[:mid])
            merged_r = self.mergeKLists(lists[mid:])
            return self.mergeKLists([merged_l, merged_r])


if __name__ == '__main__':
    a, b = ListNode(1), ListNode(3)
    c, d = ListNode(2), ListNode(4)
    solution = Solution()
    node = solution.mergeKLists([a, b, c, d])
    while node:
        print node.val
        node = node.next
