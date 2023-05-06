#https://leetcode.com/problems/contain-virus/
#A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
#The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.
#Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.
#Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.


class Solution(object):
    def containVirus(self, isInfected):
        """
        :type isInfected: List[List[int]]
        :rtype: int
        """
        if not isInfected:
            return 0
        if len(isInfected)==1:
            return isInfected[0][0]
        result=0
        for i in range(len(isInfected)):
            for j in range(len(isInfected[0])):
                result+=isInfected[i][j]
        return result
        
        
    