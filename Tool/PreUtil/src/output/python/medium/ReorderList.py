#https://leetcode.com/problems/reorder-list/
#You are given the head of a singly linked-list. The list can be represented as:
#L0 �� L1 �� �� �� Ln - 1 �� Ln
#Reorder the list to be on the following form:
#L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
#You may not modify the values in the list's nodes. Only nodes themselves may be changed.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if not head:
            return None
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        if not fast or not fast.next:
            return None
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return slow
        

    