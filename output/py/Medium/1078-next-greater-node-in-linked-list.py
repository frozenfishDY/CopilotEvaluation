#https://leetcode.com/problems/next-greater-node-in-linked-list/
#You are given the head of a linked list with n nodes.
#For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
#Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nextLargerNodes(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        res = []
        while head:
            node = head.next
            while node and node.val <= head.val:
                node = node.next
            res.append(node.val if node else 0)
            head = head.next
        return res
        

    