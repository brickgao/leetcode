#!/bin/env python2
# -*- coding: utf-8 -*-


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        cnt, head_odd, head_even = 1, ListNode(-1), ListNode(-1)
        now, now_odd, now_even = head, head_odd, head_even
        while now:
            nxt = now.next
            now.next = None
            if cnt % 2:
                now_odd.next, now_odd = now, now
            else:
                now_even.next, now_even = now, now
            now, cnt = nxt, cnt + 1
        now_odd.next = head_even.next
        return head_odd.next
