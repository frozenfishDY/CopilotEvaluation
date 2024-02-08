#https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
#In an infinite binary tree where every node has two children, the nodes are labelled in row order.
#In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.
#Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
# 
#Example 1:
#Input: label = 14
#Output: [1,3,4,14]
#Example 2:
#Input: label = 26
#Output: [1,2,6,10,26]
# 
#Constraints:
#	1 <= label <= 10^6
class Solution(object):
    def pathInZigZagTree(self, label):
        """
        :type label: int
        :rtype: List[int]
        """ 
        #Solution
        #1. Initialize the result to []
        #2. For each number in label, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #label: 10
        #ret: [1,2,6,10]
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = []
        for i in range(len(label)):
            for j in range(len(label[i])):
                if label[i][j] == 1:
                    if self.check(label, i, j):
                        ret += 1
        return ret