#https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
#You are given the head of a linked list.
#The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,
#The 1st node is assigned to the first group.
#The 2nd and the 3rd nodes are assigned to the second group.
#The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
#Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.
#Reverse the nodes in each group with an even length, and return the head of the modified linked list.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseEvenLengthGroups(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """       
        # 1. Get the length of the linked list
        # 2. If the length is even, then reverse the linked list
        # 3. If the length is odd, then return the head
        length = self.get_length(head)
        if length % 2 == 0:
            return self.reverse_linked_list(head)
        return head
        

    