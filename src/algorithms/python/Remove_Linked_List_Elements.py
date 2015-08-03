# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        pre, node = None, head
        while node:
            if node.val == val:
                if pre:
                    pre.next = node.next
                    node = node.next
                else:
                    head = head.next
                    pre, node = None, head
            else:
                pre = node
                node = node.next
        return head


if __name__ == "__main__":
    solution = Solution()
    nums = [i for i in range(10)]
    nodes = map(ListNode, nums)
    for i in range(1, 10):
        nodes[i - 1].next = nodes[i]
    node = solution.removeElements(nodes[0], 5)
    while node:
        print node.val
        node = node.next
