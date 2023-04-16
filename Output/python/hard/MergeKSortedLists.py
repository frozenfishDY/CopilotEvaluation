#https://leetcode.com/problems/merge-k-sorted-lists/
#You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
#Merge all the linked-lists into one sorted linked-list and return it.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """       
        if not lists:
            return None
        if len(lists)==1:
            return lists[0]
        if len(lists)==2:
            return self.mergeTwoLists(lists[0],lists[1])
        mid=len(lists)//2
        return self.mergeTwoLists(self.mergeKLists(lists[:mid]),self.mergeKLists(lists[mid:]))
        
    