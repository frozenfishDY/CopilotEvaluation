#https://leetcode.com/problems/set-matrix-zeroes/
#Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
#You must do it in place.


class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        m,n = len(matrix),len(matrix[0])
        row0,col0 = False,False
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    if i==0:
                        row0=True
                    if j==0:
                        col0=True
                    matrix[i][0]=0
                    matrix[0][j]=0
        for i in range(1,m):
            for j in range(1,n):
                if matrix[i][0]==0 or matrix[0][j]==0:
                    matrix[i][j]=0
        if row0:
            for j in range(n):
                matrix[0][j]=0
        if col0:
            for i in range(m):
                matrix[i][0]=0
        

    