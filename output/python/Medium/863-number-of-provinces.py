#https://leetcode.com/problems/number-of-provinces/
#There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
#A province is a group of directly or indirectly connected cities and no other cities outside of the group.
#You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
#Return the total number of provinces.
# 
#Example 1:
#Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
#Output: 2
#Example 2:
#Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
#Output: 3
# 
#Constraints:
#	1 <= n <= 200
#	n == isConnected.length
#	n == isConnected[i].length
#	isConnected[i][j] is 1 or 0.
#	isConnected[i][i] == 1
#	isConnected[i][j] == isConnected[j][i]
class Solution(object):
    def findCircleNum(self, isConnected):
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each city in isConnected, check if the city is connected to another city
        #3. If it is, add the city to the result
        #4. Return the result
        #
        #Example:
        #isConnected: [[1,1,0],[1,1,0],[0,0,1]]
        #ret: 2
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        result = 0
        for city in range(len(isConnected)):
            for other in range(len(isConnected[0])):
                if isConnected[city][other] == 1:
                    result += 1
        return result