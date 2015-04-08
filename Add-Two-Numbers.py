# -*- coding: utf-8 -*-
# Definition for singly-linked list.


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        l1_list, l2_list = [], []
        while True:
            l1_list.append(l1.val)
            if not l1.next:
                break
            l1 = l1.next
        while True:
            l2_list.append(l2.val)
            if not l2.next:
                break
            l2 = l2.next
        l1_num, l2_num = 0, 0
        for i in l1_list[::-1]:
            l1_num = l1_num * 10 + i
        for i in l2_list[::-1]:
            l2_num = l2_num * 10 + i
        ret_num = l1_num + l2_num
        ret_l = ListNode(ret_num % 10)
        tmp = ret_l
        for i in str(ret_num)[-2::-1]:
            tmp.next = ListNode(int(i))
            tmp = tmp.next
        return ret_l


if __name__ == '__main__':
    solution = Solution()
    l1, l2 = ListNode(5), ListNode(5)
    _ = solution.addTwoNumbers(l1, l2)
    while True:
        print _.val,
        if not _.next:
            break
        _ = _.next
