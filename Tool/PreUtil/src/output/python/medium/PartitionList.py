#https://leetcode.com/problems/partition-list/
#Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
#You should preserve the original relative order of the nodes in each of the two partitions.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        curr = head
        while curr:
            if curr.val < x:
                if prev.next == curr:
                    prev = curr
                else:
                    prev.next = curr.next
                    curr.next = dummy.next
                    dummy.next = curr
            else:
                prev = curr
            curr = prev.next
        return dummy.next
        

    