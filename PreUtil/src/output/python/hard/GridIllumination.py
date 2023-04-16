#https://leetcode.com/problems/grid-illumination/
#There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
#You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.
#When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.
#You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
#Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.


class Solution(object):
    def gridIllumination(self, n, lamps, queries):
        """
        :type n: int
        :type lamps: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """   

        def turn_on(lamp):
            x, y = lamp
            row[x] += 1
            col[y] += 1
            diag1[x+y] += 1
            diag2[x-y] += 1
            lamps_set.add((x,y))
            
        def turn_off(lamp):
            x, y = lamp
            row[x] -= 1
            col[y] -= 1
            diag1[x+y] -= 1
            diag2[x-y] -= 1
            lamps_set.remove((x,y))
            
        def is_illuminated(x, y):
            return row[x] > 0 or col[y] > 0 or diag1[x+y] > 0 or diag2[x-y] > 0
        
        row = collections.defaultdict(int)
        col = collections.defaultdict(int)
        diag1 = collections.defaultdict(int)
        diag2 = collections.defaultdict(int)
        lamps_set = set()
        
        for lamp in lamps:
            turn_on(lamp)
        
        ans = []
        for query in queries:
            x, y = query
            ans.append(int(is_illuminated(x, y)))
            for dx in range(-1, 2):
                for dy in range(-1, 2):
                    if (x+dx, y+dy) in lamps_set:
                        turn_off((x+dx, y+dy))
        return ans    
     
             
            