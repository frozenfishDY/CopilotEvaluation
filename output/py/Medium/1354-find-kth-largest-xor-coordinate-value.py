#https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
#You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
#The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
#Find the kth largest value (1-indexed) of all the coordinates of matrix.


class Solution(object):
    def kthLargestValue(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        result=[]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i==0 and j==0:
                    matrix[i][j]=matrix[i][j]
                elif i==0:
                    matrix[i][j]=matrix[i][j-1]^matrix[i][j]
                elif j==0:
                    matrix[i][j]=matrix[i-1][j]^matrix[i][j]
                else:
                    matrix[i][j]=matrix[i-1][j-1]^matrix[i-1][j]^matrix[i][j-1]^matrix[i][j]
                result.append(matrix[i][j])
        result.sort(reverse=True)
        return result[k-1]
        

    