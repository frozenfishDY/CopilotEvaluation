#https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """       
        if len(nums)==0:
            return None
        else:
            mid=len(nums)//2
            root=TreeNode(nums[mid])
            root.left=self.sortedArrayToBST(nums[:mid])
            root.right=self.sortedArrayToBST(nums[mid+1:])
            return root
        

    