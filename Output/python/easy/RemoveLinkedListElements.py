#https://leetcode.com/problems/remove-linked-list-elements/
#Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head==None:
            return head
        while head!=None and head.val==val:
            head=head.next
        if head==None:
            return head
        cur=head
        while cur.next!=None:
            if cur.next.val==val:
                cur.next=cur.next.next
            else:
                cur=cur.next
        return head

    