#https://leetcode.com/problems/minimum-falling-path-sum/
#Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
#A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


class Solution(object):
    def minFallingPathSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if len(matrix)==1:
            return matrix[0][0]
        for i in range(1,len(matrix)):
            for j in range(len(matrix[0])):
                if j==0:
                    matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j+1])
                elif j==len(matrix[0])-1:
                    matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j-1])
                else:
                    matrix[i][j]+=min(matrix[i-1][j],matrix[i-1][j-1],matrix[i-1][j+1])
        return min(matrix[-1])
        

    