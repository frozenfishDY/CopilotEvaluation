#https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
#Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation)._x000D_
#Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#_x000D_
#_x000D_
#Input: a = 2, b = 6, c = 5_x000D_
#Output: 3_x000D_
#Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: a = 4, b = 2, c = 7_x000D_
#Output: 1_x000D_
#_x000D_
#_x000D_
#Example 3:_x000D_
#_x000D_
#_x000D_
#Input: a = 1, b = 2, c = 3_x000D_
#Output: 0_x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= a <= 10^9_x000D_
#	1 <= b <= 10^9_x000D_
#	1 <= c <= 10^9_x000D_
class Solution(object):
    def minFlips(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        # Approach 1: Bit Manipulation
		# Time Complexity: O(log(max(a, b, c)))
		# Space Complexity: O(1)
		# Runtime: 20 ms, faster than 100.00% of Python online submissions for Minimum Flips to Make a OR b Equal to c.
		# Memory Usage: 13.4 MB, less than 100.00% of Python online submissions for Minimum Flips to Make a OR b Equal to c.
        ans = 0
        while a or b or c:
            if c & 1:
                ans += not (a | b)
            else:
                ans += (a & 1) + (b & 1)
            a >>= 1
            b >>= 1
            c >>= 1
        return ans