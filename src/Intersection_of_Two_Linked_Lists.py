# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        nodeA, nodeB = headA, headB
        lengthA, lengthB = 0, 0
        while nodeA:
            nodeA = nodeA.next
            lengthA += 1
        while nodeB:
            nodeB = nodeB.next
            lengthB += 1
        nodeA, nodeB = headA, headB
        if lengthA > lengthB:
            for i in range(abs(lengthA - lengthB)):
                nodeA = nodeA.next
        else:
            for i in range(abs(lengthA - lengthB)):
                nodeB = nodeB.next
        while nodeA and nodeB:
            if nodeA == nodeB:
                return nodeA
            nodeA = nodeA.next
            nodeB = nodeB.next
        return None


if __name__ == "__main__":
    solution = Solution()
    la = [1, 3, 5, 6, 7, 8, 9, 10]
    lb = [2, 4, 6, 7, 8, 9, 10]
    la = map(lambda x: ListNode(x), la)
    lb = map(lambda x: ListNode(x), lb)
    for i in range(len(la) - 1):
        la[i].next = la[i + 1]
    for i in range(len(lb) - 1):
        lb[i].next = lb[i + 1]
    lb[1].next = la[3]
    print solution.getIntersectionNode(la[0], lb[0]).val
