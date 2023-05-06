#https://leetcode.com/problems/maximum-total-importance-of-roads/
#You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.
#You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
#You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.
#Return the maximum total importance of all roads possible after assigning the values optimally.


class Solution(object):
    def maximumImportance(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """      
        # 1. find the maximum total importance of all roads possible after assigning the values optimally.
        # 2. return the maximum total importance of all roads possible after assigning the values optimally.
        # 1. find the maximum total importance of all roads possible after assigning the values optimally.
        # 2. return the maximum total importance of all roads possible after assigning the values optimally.
        return self.maximumImportanceFromIndex(n, roads, 0, 0)
        
       
        
    