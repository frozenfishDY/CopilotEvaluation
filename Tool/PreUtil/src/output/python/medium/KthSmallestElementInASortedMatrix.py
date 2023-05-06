#https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
#Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
#Note that it is the kth smallest element in the sorted order, not the kth distinct element.
#You must find a solution with a memory complexity better than O(n2).


class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """       
        return sorted([matrix[i][j] for i in range(len(matrix)) for j in range(len(matrix[0]))])[k-1]
        
        

    