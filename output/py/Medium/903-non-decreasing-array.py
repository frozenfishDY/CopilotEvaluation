#https://leetcode.com/problems/non-decreasing-array/
#Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
#We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
# 
#Example 1:
#Input: nums = [4,2,3]
#Output: true
#Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
#Example 2:
#Input: nums = [4,2,1]
#Output: false
#Explanation: You cannot get a non-decreasing array by modifying at most one element.
# 
#Constraints:
#	n == nums.length
#	1 <= n <= 104
#	-105 <= nums[i] <= 105
class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #Solution
        #1. Initialize the result to -1
        #2. For each number in nums, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #nums: [4,2,3]
        #ret: true
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = [-1] * len(nums)
        for num in nums:
            for i in range(len(ret)):
                if num > ret[i]:
                    ret[i] = num

        return ret