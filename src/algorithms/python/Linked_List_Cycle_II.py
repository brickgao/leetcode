# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        if not head:
            return None
        node1, node2 = head, head
        while node1 and node2:
            node1 = node1.next
            node2 = node2.next.next if node2.next else node2.next
            if node1 == node2:
                break
        if not node1 or not node2:
            return None
        node1 = head
        while node1 is not node2:
            node1, node2 = node1.next, node2.next
        return node1


if __name__ == "__main__":
    solution = Solution()
    a, b = ListNode(1), ListNode(2)
    a.next, b.next = b, b
    print solution.detectCycle(a).val
