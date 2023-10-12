#https://leetcode.com/problems/sum-of-square-numbers/
#Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
# 
#Example 1:
#Input: c = 5
#Output: true
#Explanation: 1 * 1 + 2 * 2 = 5
#Example 2:
#Input: c = 3
#Output: false
# 
#Constraints:
#	0 <= c <= 231 - 1
class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        #Solution
        #1. Use two pointers, low and high, to represent the two numbers
        #2. If low^2 + high^2 == c, return True
        #3. If low^2 + high^2 < c, move low to the next number
        #4. If low^2 + high^2 > c, move high to the previous number
        #
        #Example:
        #c = 5
        #ret = True
        #
        #Time complexity: O(sqrt(c))
        #Space complexity: O(1)

        low, high = 0, int(math.sqrt(c))
        while low <= high:
            if low ** 2 + high ** 2 == c:
                return True
            elif low ** 2 + high ** 2 < c:
                low += 1
            else:
                high -= 1
        return False