#https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
#Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
# 
#Example 1:
#Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
#Output: true
#Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
#Example 2:
#Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
#Output: false
#Explanation: It is impossible to make mat equal to target by rotating mat.
#Example 3:
#Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
#Output: true
#Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
# 
#Constraints:
#	n == mat.length == target.length
#	n == mat[i].length == target[i].length
#	1 <= n <= 10
#	mat[i][j] and target[i][j] are either 0 or 1.
class Solution(object):
    def findRotation(self, mat, target):
        """
        :type mat: List[List[int]]
        :type target: List[List[int]]
        :rtype: bool
        """
        def rotate_90_degrees_clockwise(mat):
            return [[mat[i][j] for i in range(len(mat))] for j in range(len(mat[0])-1,-1,-1)]

        for i in range(4):
            if mat == target:
                return True
            else:
                mat = rotate_90_degrees_clockwise(mat)
        return False
