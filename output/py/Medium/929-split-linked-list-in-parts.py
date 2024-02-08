#https://leetcode.com/problems/split-linked-list-in-parts/
#Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
#The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
#The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
#Return an array of the k parts.
# 
#Example 1:
#Input: head = [1,2,3], k = 5
#Output: [[1],[2],[3],[],[]]
#Explanation:
#The first element output[0] has output[0].val = 1, output[0].next = null.
#The last element output[4] is null, but its string representation as a ListNode is [].
#Example 2:
#Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
#Output: [[1,2,3,4],[5,6,7],[8,9,10]]
#Explanation:
#The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
# 
#Constraints:
#	The number of nodes in the list is in the range [0, 1000].
#	0 <= Node.val <= 1000
#	1 <= k <= 50
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def splitListToParts(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        #Solution
        #1. Initialize the result to []
        #2. For each number in head, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #head: [1,2,3], k = 5
        #ret: [[1],[2],[3],[],[]]
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = []
        for i in range(len(head)):
            for j in range(len(head[i])):
                if head[i][j] == 1:
                    if self.check(head, i, j):
                        ret += 1
        return ret