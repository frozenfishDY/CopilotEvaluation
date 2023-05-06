#https://leetcode.com/problems/average-of-levels-in-binary-tree/
#Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """      
        if root==None:
            return []
        else:
            q=[root]
            res=[]
            while len(q)>0:
                n=len(q)
                sum=0
                for i in range(n):
                    sum+=q[0].val
                    if q[0].left!=None:
                        q.append(q[0].left)
                    if q[0].right!=None:
                        q.append(q[0].right)
                    q.pop(0)
                res.append(sum/n)
            return res
        

    