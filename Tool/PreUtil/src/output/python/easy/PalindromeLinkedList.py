#https://leetcode.com/problems/palindrome-linked-list/
#Given the head of a singly linked list, return true if it is a palindrome or false otherwise.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """ 
        if head==None:
            return True
        if head.next==None:
            return True
        list=[]
        while head!=None:
            list.append(head.val)
            head=head.next
        for i in range(0,len(list)/2):
            if list[i]!=list[len(list)-1-i]:
                return False
        return True

    