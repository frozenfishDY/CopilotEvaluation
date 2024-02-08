#https://leetcode.com/problems/out-of-boundary-paths/
#There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
#Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
# 
#Example 1:
#Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
#Output: 6
#Example 2:
#Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
#Output: 12
# 
#Constraints:
#	1 <= m, n <= 50
#	0 <= maxMove <= 50
#	0 <= startRow < m
#	0 <= startColumn < n
class Solution(object):
    def findPaths(self, m, n, maxMove, startRow, startColumn):
        """
        :type m: int
        :type n: int
        :type maxMove: int
        :type startRow: int
        :type startColumn: int
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in nums, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #nums: [1,1,1,1,1], target: 3
        #ret: 5
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = 0
        for num in nums:
            for i in range(len(ret)):
                if num >= ret[i][-1]:
                    ret.append(ret[i] + [num])
            ret.append([num])

        return [x for x in ret if len(x) > 1]