#https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
#Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences._x000D_
#_x000D_
#After doing so, return the head of the final linked list.  You may return any such answer._x000D_
# 
#(Note that in the examples below, all sequences are serializations of ListNode objects.)
#Example 1:
#Input: head = [1,2,-3,3,1]
#Output: [3,1]
#Note: The answer [1,2,1] would also be accepted.
#Example 2:
#Input: head = [1,2,3,-3,4]
#Output: [1,2,4]
#Example 3:
#Input: head = [1,2,3,-3,-2]
#Output: [1]
# 
#Constraints:
#	The given linked list will contain between 1 and 1000 nodes.
#	Each node in the linked list has -1000 <= node.val <= 1000.
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeZeroSumSublists(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # Approach 1: HashMap
        # Time Complexity: O(N)
        # Space Complexity: O(N)
        # Runtime: 28 ms, faster than 99.48% of Python online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
        # Memory Usage: 13.7 MB, less than 100.00% of Python online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
        dummy = ListNode(0)
        dummy.next = head
        prefix = 0
        seen = collections.OrderedDict()
        while dummy:
            prefix += dummy.val
            node = seen.get(prefix, dummy)
            while prefix in seen:
                seen.popitem()
            seen[prefix] = node
            node.next = dummy.next
            dummy = dummy.next
        return dummy