#https://leetcode.com/problems/insertion-sort-list/
#Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
#The steps of the insertion sort algorithm:
#Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
#At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
#It repeats until no input elements remain.
#The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        if not fast or not fast.next:
            return None
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return slow
        

    