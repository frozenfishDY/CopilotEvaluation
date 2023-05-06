#https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/
#You are given a 2D integer array tiles where tiles[i] = [li, ri] represents that every tile j in the range li <= j <= ri is colored white.
#You are also given an integer carpetLen, the length of a single carpet that can be placed anywhere.
#Return the maximum number of white tiles that can be covered by the carpet.


class Solution(object):
    def maximumWhiteTiles(self, tiles, carpetLen):
        """
        :type tiles: List[List[int]]
        :type carpetLen: int
        :rtype: int
        """ 
        # 1. find the maximum white tiles that can be covered by the carpet
        # 2. return the maximum white tiles that can be covered by the carpet
        # 1. find the maximum white tiles that can be covered by the carpet
        # 2. return the maximum white tiles that can be covered by the carpet
        return self.maximumWhiteTilesFromIndex(tiles, carpetLen, 0, 0)

        
    