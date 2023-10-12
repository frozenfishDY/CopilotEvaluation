#https://leetcode.com/problems/maximum-alternating-subsequence-sum/
#The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices._x000D_
#_x000D_
#_x000D_
#	For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4._x000D_
#_x000D_
#_x000D_
#Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence)._x000D_
#_x000D_
#_x000D_
#_x000D_
#_x000D_
#A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: nums = [4,2,5,3]_x000D_
#Output: 7_x000D_
#Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7._x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: nums = [5,6,7,8]_x000D_
#Output: 8_x000D_
#Explanation: It is optimal to choose the subsequence [8] with alternating sum 8._x000D_
#_x000D_
#_x000D_
#Example 3:_x000D_
#_x000D_
#_x000D_
#Input: nums = [6,2,1,2,4,5]_x000D_
#Output: 10_x000D_
#Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10._x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= nums.length <= 105_x000D_
#	1 <= nums[i] <= 105_x000D_
class Solution(object):
    def maxAlternatingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(max(nums[i] - nums[i - 1], 0) for i in range(1, len(nums)))
