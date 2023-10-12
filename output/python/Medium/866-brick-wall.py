#https://leetcode.com/problems/brick-wall/
#There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.
#Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
#Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.
# 
#Example 1:
#Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
#Output: 2
#Example 2:
#Input: wall = [[1],[1],[1]]
#Output: 3
# 
#Constraints:
#	n == wall.length
#	1 <= n <= 104
#	1 <= wall[i].length <= 104
#	1 <= sum(wall[i].length) <= 2 * 104
#	sum(wall[i]) is the same for each row i.
#	1 <= wall[i][j] <= 231 - 1
class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in nums, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #nums: [1,2,1]
        #ret: [2,-1,2]
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = [-1] * len(nums)
        for num in nums:
            for i in range(len(ret)):
                if num > ret[i]:
                    ret[i] = num

        return ret