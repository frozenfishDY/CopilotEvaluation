#https://leetcode.com/problems/next-greater-element-iii/
#Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
#Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
# 
#Example 1:
#Input: n = 12
#Output: 21
#Example 2:
#Input: n = 21
#Output: -1
# 
#Constraints:
#	1 <= n <= 231 - 1
class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        #Solution
        #1. Find the first digit that is less than the next digit
        #2. Find the smallest digit that is greater than the first digit
        #3. Swap the first digit with the smallest digit
        #4. Reverse the digits after the first digit
        #5. Return the result
        #
        #Example:
        #n: 1234
        #ret: 1243
        #
        #Time complexity: O(n)
        #Space complexity: O(n)
        
        if n < 10:
            return -1
        
        digits = list(str(n))
        i = len(digits) - 2
        while i >= 0 and digits[i] >= digits[i + 1]:
            i -= 1
        if i == -1:
            return -1
        j = len(digits) - 1
        while j > i and digits[j] <= digits[i]:
            j -= 1
        digits[i], digits[j] = digits[j], digits[i]
        digits[i + 1:] = digits[i + 1:][::-1]
        ret = int(''.join(digits))
        return ret if ret < 2147483647 else -1
        