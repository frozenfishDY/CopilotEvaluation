#https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
#Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs._x000D_
#_x000D_
#A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: nums = [1,4,2,7], low = 2, high = 6_x000D_
#Output: 6_x000D_
#Explanation: All nice pairs (i, j) are as follows:_x000D_
#    - (0, 1): nums[0] XOR nums[1] = 5 _x000D_
#    - (0, 2): nums[0] XOR nums[2] = 3_x000D_
#    - (0, 3): nums[0] XOR nums[3] = 6_x000D_
#    - (1, 2): nums[1] XOR nums[2] = 6_x000D_
#    - (1, 3): nums[1] XOR nums[3] = 3_x000D_
#    - (2, 3): nums[2] XOR nums[3] = 5_x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: nums = [9,8,4,2,1], low = 5, high = 14_x000D_
#Output: 8_x000D_
#Explanation: All nice pairs (i, j) are as follows:_x000D_
#​​​​​    - (0, 2): nums[0] XOR nums[2] = 13_x000D_
#    - (0, 3): nums[0] XOR nums[3] = 11_x000D_
#    - (0, 4): nums[0] XOR nums[4] = 8_x000D_
#    - (1, 2): nums[1] XOR nums[2] = 12_x000D_
#    - (1, 3): nums[1] XOR nums[3] = 10_x000D_
#    - (1, 4): nums[1] XOR nums[4] = 9_x000D_
#    - (2, 3): nums[2] XOR nums[3] = 6_x000D_
#    - (2, 4): nums[2] XOR nums[4] = 5_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= nums.length <= 2 * 104_x000D_
#	1 <= nums[i] <= 2 * 104_x000D_
#	1 <= low <= high <= 2 * 104_x000D_
class Solution(object):
    def countPairs(self, nums, low, high):
        """
        :type nums: List[int]
        :type low: int
        :type high: int
        :rtype: int
        """
        