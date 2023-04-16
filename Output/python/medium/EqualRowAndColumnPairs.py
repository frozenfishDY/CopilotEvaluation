#https://leetcode.com/problems/equal-row-and-column-pairs/
#Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
#A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).


class Solution(object):
    def equalPairs(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """ 
        # 1. find the number of pairs (ri, cj) such that row ri and column cj are equal
        # 2. return the number of pairs (ri, cj) such that row ri and column cj are equal
        # 1. find the number of pairs (ri, cj) such that row ri and column cj are equal
        # 2. return the number of pairs (ri, cj) such that row ri and column cj are equal
        return self.equalPairsFromIndex(grid, 0, 0)
        
        
    