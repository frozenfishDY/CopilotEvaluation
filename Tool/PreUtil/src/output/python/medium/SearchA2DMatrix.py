#https://leetcode.com/problems/search-a-2d-matrix/
#You are given an m x n integer matrix matrix with the following two properties:
#Each row is sorted in non-decreasing order.
#The first integer of each row is greater than the last integer of the previous row.
#Given an integer target, return true if target is in matrix or false otherwise.
#You must write a solution in O(log(m * n)) time complexity.


class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m,n = len(matrix),len(matrix[0])
        left,right = 0,m*n-1
        while left<=right:
            mid = (left+right)//2
            if matrix[mid//n][mid%n]==target:
                return True
            elif matrix[mid//n][mid%n]<target:
                left=mid+1
            else:
                right=mid-1
        return False
        

    