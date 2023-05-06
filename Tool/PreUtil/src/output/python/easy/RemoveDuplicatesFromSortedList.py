#https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None:
            return head
        else:
            temp=head
            while temp.next!=None:
                if temp.val==temp.next.val:
                    temp.next=temp.next.next
                else:
                    temp=temp.next
            return head

    