#https://leetcode.com/problems/complex-number-multiplication/
#A complex number can be represented as a string on the form "real+imaginaryi" where:
#	real is the real part and is an integer in the range [-100, 100].
#	imaginary is the imaginary part and is an integer in the range [-100, 100].
#	i2 == -1.
#Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.
# 
#Example 1:
#Input: num1 = "1+1i", num2 = "1+1i"
#Output: "0+2i"
#Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
#Example 2:
#Input: num1 = "1+-1i", num2 = "1+-1i"
#Output: "0+-2i"
#Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
# 
#Constraints:
#	num1 and num2 are valid complex numbers.
class Solution(object):
    def complexNumberMultiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        #Solution
		#1. Split num1 and num2 into their real and imaginary parts
		#2. Multiply the real parts and imaginary parts
		#3. Return the result
		#
		#Example:
		#num1: "1+1i", num2: "1+1i"
		#ret: "0+2i"
		#
		#Time complexity: O(1)
		#Space complexity: O(1)

        r1, i1 = num1.split("+")
        r2, i2 = num2.split("+")
        r1, i1 = int(r1), int(i1[:-1])
        r2, i2 = int(r2), int(i2[:-1])
        r = r1 * r2 - i1 * i2
        i = r1 * i2 + r2 * i1
        return str(r) + "+" + str(i) + "i"