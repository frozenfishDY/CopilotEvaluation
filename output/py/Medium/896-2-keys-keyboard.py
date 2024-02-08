#https://leetcode.com/problems/2-keys-keyboard/
#There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:
#	Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
#	Paste: You can paste the characters which are copied last time.
#Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.
# 
#Example 1:
#Input: n = 3
#Output: 3
#Explanation: Initially, we have one character 'A'.
#In step 1, we use Copy All operation.
#In step 2, we use Paste operation to get 'AA'.
#In step 3, we use Paste operation to get 'AAA'.
#Example 2:
#Input: n = 1
#Output: 0
# 
#Constraints:
#	1 <= n <= 1000
class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
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

        ret = 0
        for i in range(2, n + 1):
            while n % i == 0:
                ret += i
                n /= i

        return ret