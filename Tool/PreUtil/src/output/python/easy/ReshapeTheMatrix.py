#https://leetcode.com/problems/reshape-the-matrix/
#In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
#You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
#The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
#If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.


class Solution(object):
    def matrixReshape(self, mat, r, c):
        """
        :type mat: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """      
        if len(mat)*len(mat[0])!=r*c:
            return mat
        else:
            result=[]
            temp=[]
            for i in range(len(mat)):
                for j in range(len(mat[0])):
                    temp.append(mat[i][j])
                    if len(temp)==c:
                        result.append(temp)
                        temp=[]
            return result

    