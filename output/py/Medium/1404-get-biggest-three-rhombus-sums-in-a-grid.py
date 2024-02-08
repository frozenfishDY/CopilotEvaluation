#https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
#You are given an m x n integer matrix grid​​​.
#A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
#Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
#Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.
# 
#Example 1:
#Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
#Output: [228,216,211]
#Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
#- Blue: 20 + 3 + 200 + 5 = 228
#- Red: 200 + 2 + 10 + 4 = 216
#- Green: 5 + 200 + 4 + 2 = 211
#Example 2:
#Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
#Output: [20,9,8]
#Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
#- Blue: 4 + 2 + 6 + 8 = 20
#- Red: 9 (area 0 rhombus in the bottom right corner)
#- Green: 8 (area 0 rhombus in the bottom middle)
#Example 3:
#Input: grid = [[7,7,7]]
#Output: [7]
#Explanation: All three possible rhombus sums are the same, so return [7].
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 50
#	1 <= grid[i][j] <= 105
class Solution(object):
    def getBiggestThree(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        m, n = len(grid), len(grid[0])
        res = set()
        for i in range(m):
            for j in range(n):
                for k in range(min(i, m - i - 1), -1, -1):
                    if j - k < 0 or j + k >= n:
                        break
                    sum = 0
                    x, y = i, j
                    for l in range(k):
                        sum += grid[x][y]
                        sum += grid[x][y - 1]
                        sum += grid[x - 1][y]
                        sum += grid[x - 1][y - 1]
                        x -= 1
                        y -= 1
                    sum += grid[x][y]
                    res.add(sum)
        return sorted(res, reverse = True)[:3]