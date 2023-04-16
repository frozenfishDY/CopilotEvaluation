#https://leetcode.com/problems/linked-list-components/
#You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
#Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def numComponents(self, head, nums):
        """
        :type head: ListNode
        :type nums: List[int]
        :rtype: int
        """
        nums = set(nums)
        res = 0
        while head:
            if head.val in nums and (not head.next or head.next.val not in nums):
                res += 1
            head = head.next
        return res
        

    