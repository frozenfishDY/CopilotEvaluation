#https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
#You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
#The score of a path between two cities is defined as the minimum distance of a road in this path.
#Return the minimum possible score of a path between cities 1 and n.
#Note:
#A path is a sequence of roads between two cities.
#It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
#The test cases are generated such that there is at least one path between 1 and n.


class Solution(object):
    def minScore(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        res = 0
        for i in range(len(roads)):
            for j in range(i+1,len(roads)):
                if roads[i][2] > roads[j][2]:
                    roads[i],roads[j] = roads[j],roads[i]
        for i in range(len(roads)):
            if roads[i][0] == 1 or roads[i][1] == 1:
                res = roads[i][2]
                break
        return res
        

    