#https://leetcode.com/problems/swim-in-rising-water/
#You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
#The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
#Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).


class Solution(object):
    def swimInWater(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """       
        # 1. find the max value in the grid
        # 2. find the min value in the grid
        # 3. find the mid value between max and min
        # 4. check if the mid value is reachable
        # 5. if not, set min to mid+1
        # 6. if yes, set max to mid
        # 7. repeat 3-6 until min==max
        # 8. return min
        
        # 1. find the max value in the grid
        max_val = 0
        for row in grid:
            for val in row:
                if val > max_val:
                    max_val = val
        
        # 2. find the min value in the grid
        min_val = max_val
        for row in grid:
            for val in row:
                if val < min_val:
                    min_val = val
        
        # 3. find the mid value between max and min
        mid_val = (max_val + min_val) // 2
        
        # 4. check if the mid value is reachable
        # 5. if not, set min to mid+1
        # 6. if yes, set max to mid
        # 7. repeat 3-6 until min==max
        while min_val < max_val:
            # 4. check if the mid value is reachable
            if self.is_reachable(grid, mid_val):
                # 6. if yes, set max to mid
                max_val = mid_val
            else:
                # 5. if not, set min to mid+1
                min_val = mid_val + 1
            
            # 3. find the mid value between max and min
            mid_val = (max_val + min_val) // 2
        
        # 8. return min
        return min_val
            
          