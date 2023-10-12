#https://leetcode.com/problems/largest-values-from-labels/
#There is a set of n items. You are given two integer arrays values and labels where the value and the label of the ith element are values[i] and labels[i] respectively. You are also given two integers numWanted and useLimit.
#Choose a subset s of the n elements such that:
#	The size of the subset s is less than or equal to numWanted.
#	There are at most useLimit items with the same label in s.
#The score of a subset is the sum of the values in the subset.
#Return the maximum score of a subset s.
# 
#Example 1:
#Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
#Output: 9
#Explanation: The subset chosen is the first, third, and fifth items.
#Example 2:
#Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
#Output: 12
#Explanation: The subset chosen is the first, second, and third items.
#Example 3:
#Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
#Output: 16
#Explanation: The subset chosen is the first and fourth items.
# 
#Constraints:
#	n == values.length == labels.length
#	1 <= n <= 2 * 104
#	0 <= values[i], labels[i] <= 2 * 104
#	1 <= numWanted, useLimit <= n
class Solution(object):
    def largestValsFromLabels(self, values, labels, numWanted, useLimit):
        """
        :type values: List[int]
        :type labels: List[int]
        :type numWanted: int
        :type useLimit: int
        :rtype: int
        """
        #Solution
        #1. Initialize the result to []
        #2. For each number in values, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #values: [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
        #ret: 9
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = 0
        for i in range(len(values)):
            for j in range(len(values[i])):
                if values[i][j] == 1:
                    if self.check(values, i, j):
                        ret += 1
        return ret