#https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/
#You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1. The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).
#You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).
#Return true if it is possible to make the matrix disconnect or false otherwise.
#Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.


class Solution(object):
    def isPossibleToCutPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        m,n = len(grid),len(grid[0])
        if m==1 and n==1:
            return False
        if m==1:
            for i in range(1,n):
                if grid[0][i]==0:
                    return True
            return False
        if n==1:
            for i in range(1,m):
                if grid[i][0]==0:
                    return True
            return False
        if grid[0][1]==0 and grid[1][0]==0:
            return True
        if grid[m-1][n-2]==0 and grid[m-2][n-1]==0:
            return True
        for i in range(1,m-1):
            if grid[i][0]==0 and grid[i][1]==0:
                return True
        for i in range(1,n-1):
            if grid[0][i]==0 and grid[1][i]==0:
                return True
        for i in range(1,m-1):
            if grid[i][n-1]==0 and grid[i][n-2]==0:
                return True
        for i in range(1,n-1):
            if grid[m-1][i]==0 and grid[m-2][i]==0:
                return True
        return False
        

    