#https://leetcode.com/problems/remove-nodes-from-linked-list/
#You are given the head of a linked list.
#Remove every node which has a node with a strictly greater value anywhere to the right side of it.
#Return the head of the modified linked list.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head:
            return None
        if not head.next:
            return head
        if head.val < head.next.val:
            head.next = self.removeNodes(head.next)
            return head
        else:
            return self.removeNodes(head.next)
        

    