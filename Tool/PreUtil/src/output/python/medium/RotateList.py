#https://leetcode.com/problems/rotate-list/
#Given the head of a linked list, rotate the list to the right by k places.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return None
        if not head.next:
            return head
        if k == 0:
            return head
        # get length
        length = 1
        cur = head
        while cur.next:
            cur = cur.next
            length += 1
        # make it a circle
        cur.next = head
        # find the new tail
        cur = head
        for i in range(length - k % length - 1):
            cur = cur.next
        # find the new head
        new_head = cur.next
        # break the circle
        cur.next = None
        return new_head
        

    