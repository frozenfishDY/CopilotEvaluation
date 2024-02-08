#https://leetcode.com/problems/circular-permutation-in-binary-representation/
#Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :_x000D_
#_x000D_
#_x000D_
#	p[0] = start_x000D_
#	p[i] and p[i+1] differ by only one bit in their binary representation._x000D_
#	p[0] and p[2^n -1] must also differ by only one bit in their binary representation._x000D_
#_x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: n = 2, start = 3_x000D_
#Output: [3,2,0,1]_x000D_
#Explanation: The binary representation of the permutation is (11,10,00,01). _x000D_
#All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]_x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: n = 3, start = 2_x000D_
#Output: [2,6,7,5,4,0,1,3]_x000D_
#Explanation: The binary representation of the permutation is (010,110,111,101,100,000,001,011)._x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= n <= 16_x000D_
#	0 <= start < 2 ^ n_x000D_
class Solution(object):
    def circularPermutation(self, n, start):
        """
        :type n: int
        :type start: int
        :rtype: List[int]
        """
        # Approach 1: Gray Code
        # Time Complexity: O(2^N)
        # Space Complexity: O(1)
        # Runtime: 120 ms, faster than 100.00% of Python online submissions for Circular Permutation in Binary Representation.
        # Memory Usage: 14.5 MB, less than 100.00% of Python online submissions for Circular Permutation in Binary Representation.
        return [start ^ (i ^ i >> 1) for i in range(1 << n)]