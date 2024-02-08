#https://leetcode.com/problems/magic-squares-in-grid/
#A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
#Given a row x col grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).


class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """       
        if len(grid)<3 or len(grid[0])<3:
            return 0
        count=0
        for i in range(len(grid)-2):
            for j in range(len(grid[0])-2):
                if self.isMagicSquare(grid,i,j):
                    count+=1
        return count
        
        

    