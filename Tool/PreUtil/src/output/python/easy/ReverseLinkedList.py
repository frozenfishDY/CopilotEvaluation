#https://leetcode.com/problems/reverse-linked-list/
#Given the head of a singly linked list, reverse the list, and return the reversed list.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """ 
        if head==None:
            return head
        cur=head
        prev=None
        while cur!=None:
            next=cur.next
            cur.next=prev
            prev=cur
            cur=next
        return prev

    