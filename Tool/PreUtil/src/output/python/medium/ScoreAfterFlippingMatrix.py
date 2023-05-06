#https://leetcode.com/problems/score-after-flipping-matrix/
#You are given an m x n binary matrix grid.
#A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
#Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
#Return the highest possible score after making any number of moves (including zero moves).


class Solution(object):
    def matrixScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        for i in range(len(grid)):
            if grid[i][0] == 0:
                for j in range(len(grid[0])):
                    grid[i][j] = 1 - grid[i][j]
        for j in range(len(grid[0])):
            count = 0
            for i in range(len(grid)):
                if grid[i][j] == 1:
                    count += 1
            if count < len(grid) - count:
                for i in range(len(grid)):
                    grid[i][j] = 1 - grid[i][j]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                res += grid[i][j] * 2 ** (len(grid[0]) - 1 - j)
        return res
        

    