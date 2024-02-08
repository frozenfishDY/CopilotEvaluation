#https://leetcode.com/problems/largest-1-bordered-square/
#Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: grid = [[1,1,1],[1,0,1],[1,1,1]]_x000D_
#Output: 9_x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: grid = [[1,1,0,0]]_x000D_
#Output: 1_x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= grid.length <= 100_x000D_
#	1 <= grid[0].length <= 100_x000D_
#	grid[i][j] is 0 or 1_x000D_
class Solution(object):
    def largest1BorderedSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # Approach 1: Dynamic Programming
        # Time Complexity: O(N^3)
        # Space Complexity: O(N^2)
        # Runtime: 156 ms, faster than 75.00% of Python online submissions for Largest 1-Bordered Square.
        # Memory Usage: 14.2 MB, less than 100.00% of Python online submissions for Largest 1-Bordered Square.
        ans = 0
        rows, cols = len(grid), len(grid[0])
        left = [[0] * cols for _ in range(rows)]
        top = [[0] * cols for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    left[i][j] = left[i][j - 1] + 1 if j else 1
                    top[i][j] = top[i - 1][j] + 1 if i else 1
                    for k in range(min(left[i][j], top[i][j]), 0, -1):
                        if top[i][j - k + 1] >= k and left[i - k + 1][j] >= k:
                            ans = max(ans, k * k)
                            break
        return ans