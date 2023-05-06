#https://leetcode.com/problems/increment-submatrices-by-one/
#You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.
#You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:
#Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for for all row1i <= x <= row2i and col1i <= y <= col2i.
#Return the matrix mat after performing every query.


class Solution(object):
    def rangeAddQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[List[int]]
        """     
        mat = [[0] * n for _ in range(n)]
        for row1, col1, row2, col2 in queries:
            mat[row1][col1] += 1
            if row2 + 1 < n:
                mat[row2 + 1][col1] -= 1
            if col2 + 1 < n:
                mat[row1][col2 + 1] -= 1
            if row2 + 1 < n and col2 + 1 < n:
                mat[row2 + 1][col2 + 1] += 1
        for i in range(n):
            for j in range(n):
                if i > 0:
                    mat[i][j] += mat[i - 1][j]
                if j > 0:
                    mat[i][j] += mat[i][j - 1]
                if i > 0 and j > 0:
                    mat[i][j] -= mat[i - 1][j - 1]
        return mat

        

    