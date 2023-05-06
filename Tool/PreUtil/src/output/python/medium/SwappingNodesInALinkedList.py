#https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
#You are given the head of a linked list, and an integer k.
#Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapNodes(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        result=[]
        while head:
            result.append(head.val)
            head=head.next
        result[k-1],result[len(result)-k]=result[len(result)-k],result[k-1]
        return result
        

    