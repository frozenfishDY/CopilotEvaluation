#https://leetcode.com/problems/continuous-subarray-sum/
#Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
#A good subarray is a subarray where:
#	its length is at least two, and
#	the sum of the elements of the subarray is a multiple of k.
#Note that:
#	A subarray is a contiguous part of the array.
#	An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
# 
#Example 1:
#Input: nums = [23,2,4,6,7], k = 6
#Output: true
#Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
#Example 2:
#Input: nums = [23,2,6,4,7], k = 6
#Output: true
#Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
#42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
#Example 3:
#Input: nums = [23,2,6,4,7], k = 13
#Output: false
# 
#Constraints:
#	1 <= nums.length <= 105
#	0 <= nums[i] <= 109
#	0 <= sum(nums[i]) <= 231 - 1
#	1 <= k <= 231 - 1
class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        #Solution
        #1. Initialize the sum to 0
        #2. Iterate through every number in nums
        #3. Add the number to sum
        #4. If the sum is a multiple of k, return True
        #5. Return False
        #
        #Example:
        #nums: [23,2,4,6,7]
        #k: 6
        #sum: 0
        #num: 23
        #sum: 23
        #num: 2
        #sum: 25
        #num: 4
        #sum: 29
        #num: 6
        #sum: 35
        #num: 7
        #sum: 42
        #return True
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            if k != 0:
                sum = sum % k
            if sum == 0 and i > 0:
                return True
            for j in range(i - 1, -1, -1):
                sum -= nums[j]
                if k != 0:
                    sum = sum % k
                if sum == 0:
                    return True

        return False