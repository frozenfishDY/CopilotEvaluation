#https://leetcode.com/problems/search-a-2d-matrix-ii/
#Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
#Integers in each row are sorted in ascending from left to right.
#Integers in each column are sorted in ascending from top to bottom.


class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        if n == 0:
            return False
        i = 0
        j = n - 1
        while i < m and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                i += 1
            else:
                j -= 1
        return False
        

    