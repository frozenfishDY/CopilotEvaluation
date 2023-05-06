#https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
#You are given a 0-indexed m x n binary matrix grid.
#A 0-indexed m x n difference matrix diff is created with the following procedure:
#Let the number of ones in the ith row be onesRowi.
#Let the number of ones in the jth column be onesColj.
#Let the number of zeros in the ith row be zerosRowi.
#Let the number of zeros in the jth column be zerosColj.
#diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
#Return the difference matrix diff.


class Solution(object):
    def onesMinusZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """       
        # 1. Create a list of lists to hold the output
        # 2. Create a list to hold the number of ones in each row
        # 3. Create a list to hold the number of zeros in each row
        # 4. Create a list to hold the number of ones in each column
        # 5. Create a list to hold the number of zeros in each column
        # 6. Loop through the grid
        # 7. Loop through each row
        # 8. Loop through each column
        # 9. If the value is 1, then add 1 to the number of ones in the row and column
        # 10. If the value is 0, then add 1 to the number of zeros in the row and column
        # 11. Loop through the grid
        # 12. Loop through each row
        # 13. Loop through each column
        # 14. Add the number of ones in the row and column, minus the number of zeros in the row and column to the output list
        # 15. Return the output list
        output = []
        ones_row = []
        zeros_row = []
        ones_col = []
        zeros_col = []
        for row in grid:
            ones_row.append(0)
            zeros_row.append(0)
        for col in grid[0]:
            ones_col.append(0)
            zeros_col.append(0)
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 1:
                    ones_row[row] += 1
                    ones_col[col] += 1
                else:
                    zeros_row[row] += 1
                    zeros_col[col] += 1
        for row in range(len(grid)):
            output.append([])
            for col in range(len(grid[0])):
                output[row].append(ones_row[row] + ones_col[col] - zeros_row[row] - zeros_col[col])
        return output          

        

    