#https://leetcode.com/problems/largest-submatrix-with-rearrangements/
#You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
#Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.


class Solution(object):
    def largestSubmatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        result=0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j]==1:
                    matrix[i][j]=matrix[i-1][j]+1
        for i in range(len(matrix)):
            matrix[i].sort(reverse=True)
            for j in range(len(matrix[0])):
                result=max(result,matrix[i][j]*(j+1))
        return result
        

    