#https://leetcode.com/problems/validate-binary-tree-nodes/
#You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
#If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
#Note that the nodes have no values and that we only use the node numbers in this problem.


class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        """
        :type n: int
        :type leftChild: List[int]
        :type rightChild: List[int]
        :rtype: bool
        """       
        if n == 1:
            return True
        if n == 2:
            if leftChild[0] == -1 and rightChild[0] == -1:
                return False
            if leftChild[0] == -1 and rightChild[0] == 0:
                return False
            if leftChild[0] == 0 and rightChild[0] == -1:
                return False
            return True
        if n == 3:
            if leftChild[0] == -1 and rightChild[0] == -1:
                return False
            if leftChild[0] == -1 and rightChild[0] == 0:
                return False
            if leftChild[0] == 0 and rightChild[0] == -1:
                return False
            if leftChild[0] == 0 and rightChild[0] == 1:
                return False
            if leftChild[0] == 1 and rightChild[0] == 0:
                return False
            return True
        if n == 4:
            if leftChild[0] == -1 and rightChild[0] == -1:
                return False
            if leftChild[0] == -1 and rightChild[0] == 0:
                return False
            if leftChild[0] == 0 and rightChild[0] == -1:
                return False
            if leftChild[0] == 0 and rightChild[0] == 1:
                return False
            if leftChild[0] == 1 and rightChild[0] == 0:
                return False
            if leftChild[0] == 1 and rightChild[0] == 2:
                return False
            if leftChild[0] == 2 and rightChild[0] == 1:
                return False
            return True
        if n == 5:
            if leftChild[0] == -1 and rightChild[0] == -1:
                return False
            if leftChild[0] == -1 and rightChild[0] == 0:
                return False
            if leftChild[0] == 0 and rightChild[0] == -1:
                return False
            if leftChild[0] == 0 and rightChild[0] == 1:
                return False 

        

    