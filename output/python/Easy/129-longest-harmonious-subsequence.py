#https://leetcode.com/problems/longest-harmonious-subsequence/
#We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1._x000D_
#_x000D_
#Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences._x000D_
#_x000D_
#A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: nums = [1,3,2,2,5,2,3,7]_x000D_
#Output: 5_x000D_
#Explanation: The longest harmonious subsequence is [3,2,2,2,3]._x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: nums = [1,2,3,4]_x000D_
#Output: 2_x000D_
#_x000D_
#_x000D_
#Example 3:_x000D_
#_x000D_
#_x000D_
#Input: nums = [1,1,1,1]_x000D_
#Output: 0_x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= nums.length <= 2 * 104_x000D_
#	-109 <= nums[i] <= 109_x000D_
class Solution(object):_x000D_
    def findLHS(self, nums):_x000D_
        """_x000D_
        :type nums: List[int]_x000D_
        :rtype: int_x000D_
        """