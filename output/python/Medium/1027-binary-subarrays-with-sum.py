#https://leetcode.com/problems/binary-subarrays-with-sum/
#Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal._x000D_
#_x000D_
#A subarray is a contiguous part of the array._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: nums = [1,0,1,0,1], goal = 2_x000D_
#Output: 4_x000D_
#Explanation: The 4 subarrays are bolded and underlined below:_x000D_
#[1,0,1,0,1]_x000D_
#[1,0,1,0,1]_x000D_
#[1,0,1,0,1]_x000D_
#[1,0,1,0,1]_x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: nums = [0,0,0,0,0], goal = 0_x000D_
#Output: 15_x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= nums.length <= 3 * 104_x000D_
#	nums[i] is either 0 or 1._x000D_
#	0 <= goal <= nums.length_x000D_
class Solution(object):_x000D_
    def numSubarraysWithSum(self, nums, goal):_x000D_
        """_x000D_
        :type nums: List[int]_x000D_
        :type goal: int_x000D_
        :rtype: int_x000D_
        """