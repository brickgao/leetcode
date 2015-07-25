# -*- coding: utf-8 -*-


# Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None


class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if head is None:
            return None
        n_head, rec = None, {'None': None}
        pre, node = None, head
        while node:
            n_node = RandomListNode(node.label)
            rec[str(node)] = n_node
            if pre:
                pre.next = n_node
            else:
                n_head = n_node
            pre = n_node
            node = node.next
        node, n_node = head, n_head
        while node:
            n_node.random = rec[str(node.random)]
            node = node.next
            n_node = n_node.next
        return n_head


if __name__ == "__main__":
    solution = Solution()
    a, b = RandomListNode(1), RandomListNode(2)
    a.next = b
    a.random, b.random = a, a
    node = solution.copyRandomList(a)
    print (
        node.label, node.next.label,
        node.random.label, node.next.random.label
    )
