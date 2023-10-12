#https://leetcode.com/problems/solve-the-equation/
#Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.
#If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.
# 
#Example 1:
#Input: equation = "x+5-3+x=6+x-2"
#Output: "x=2"
#Example 2:
#Input: equation = "x=x"
#Output: "Infinite solutions"
#Example 3:
#Input: equation = "2x=x"
#Output: "x=0"
# 
#Constraints:
#	3 <= equation.length <= 1000
#	equation has exactly one '='.
#	equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
class Solution(object):
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        #Solution
        #1. Initialize the result to 0
        #2. Iterate through every character in s
        #3. For each character, find the maximum length of repeating characters
        #4. Return the maximum length
        #
        #Example:
        #s = "ABAB", k = 2
        #maxLength: 0
        #i: 0
        #maxLength: 1
        #i: 1
        #maxLength: 2
        #i: 2
        #maxLength: 3
        #i: 3
        #maxLength: 4
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        maxLength = 0
        for i in range(len(s)):
            maxCount = 0
            for j in range(i, len(s)):
                if s[j] == s[i]:
                    maxCount += 1
                elif k > 0:
                    maxCount += 1
                    k -= 1
                else:
                    break

            maxLength = max(maxLength, maxCount)