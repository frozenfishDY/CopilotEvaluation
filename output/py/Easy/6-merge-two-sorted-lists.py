#https://leetcode.com/problems/merge-two-sorted-lists/
#You are given the heads of two sorted linked lists list1 and list2.
#Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
#Return the head of the merged linked list.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if list1==None:
            return list2
        elif list2==None:
            return list1
        else:
            if list1.val<list2.val:
                res=list1
                res.next=self.mergeTwoLists(list1.next,list2)
            else:
                res=list2
                res.next=self.mergeTwoLists(list1,list2.next)
            return res

    