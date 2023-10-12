#https://leetcode.com/problems/fraction-to-recurring-decimal/
#Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
#If the fractional part is repeating, enclose the repeating part in parentheses.
#If multiple answers are possible, return any of them.
#It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
# 
#Example 1:
#Input: numerator = 1, denominator = 2
#Output: "0.5"
#Example 2:
#Input: numerator = 2, denominator = 1
#Output: "2"
#Example 3:
#Input: numerator = 4, denominator = 333
#Output: "0.(012)"
# 
#Constraints:
#	-231 <= numerator, denominator <= 231 - 1
#	denominator != 0
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        # 1. sign
        sign = 1
        if (numerator > 0 and denominator < 0) or (numerator < 0 and denominator > 0):
            sign = -1
            
        # 2. absolute value
        numerator = abs(numerator)
        denominator = abs(denominator)
        
        # 3. edge cases
        if numerator % denominator == 0:
            return str(numerator // denominator * sign)
        
        # 4. integer part
        res = str(numerator // denominator) + '.'
        
        # 5. decimal part
        numerator %= denominator
        seen = {}
        while numerator != 0:
            if numerator in seen:
                res = res[:seen[numerator]] + '(' + res[seen[numerator]:] + ')'
                break
            seen[numerator] = len(res)
            numerator *= 10
            res += str(numerator // denominator)
            numerator %= denominator
        
        return res if sign == 1 else '-' + res