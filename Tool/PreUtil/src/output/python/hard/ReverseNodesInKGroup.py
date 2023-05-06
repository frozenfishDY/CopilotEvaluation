#https://leetcode.com/problems/reverse-nodes-in-k-group/
#Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
#k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
#You may not alter the values in the list's nodes, only nodes themselves may be changed.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return None
        if k==1:
            return head
        dummy=ListNode(0)
        dummy.next=head
        prev=dummy
        while prev:
            prev=self.reverse(prev,k)
        return dummy.next
        
    