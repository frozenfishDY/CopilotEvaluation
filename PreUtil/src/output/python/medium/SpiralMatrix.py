#https://leetcode.com/problems/spiral-matrix/
#Given an m x n matrix, return all elements of the matrix in spiral order.


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        m,n = len(matrix),len(matrix[0])
        res = []
        left,right,top,bottom = 0,n-1,0,m-1
        while left<=right and top<=bottom:
            for i in range(left,right+1):
                res.append(matrix[top][i])
            for i in range(top+1,bottom+1):
                res.append(matrix[i][right])
            if left<right and top<bottom:
                for i in range(right-1,left,-1):
                    res.append(matrix[bottom][i])
                for i in range(bottom,top,-1):
                    res.append(matrix[i][left])
            left,right,top,bottom = left+1,right-1,top+1,bottom-1
        return res
        

    