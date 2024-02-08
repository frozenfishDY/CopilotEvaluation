#https://leetcode.com/problems/monotone-increasing-digits/
#An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
#Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
# 
#Example 1:
#Input: n = 10
#Output: 9
#Example 2:
#Input: n = 1234
#Output: 1234
#Example 3:
#Input: n = 332
#Output: 299
# 
#Constraints:
#	0 <= n <= 109
class Solution(object):
    def monotoneIncreasingDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        #Solution
        #1. Initialize the result to []
        #2. For each number in n, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #n: 10
        #ret: 9
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = []
        for i in range(len(n)):
            for j in range(len(n[i])):
                if n[i][j] == 1:
                    if self.check(n, i, j):
                        ret += 1
        return ret

        
        