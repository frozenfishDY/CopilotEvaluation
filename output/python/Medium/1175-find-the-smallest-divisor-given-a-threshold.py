#https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
#Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
#The test cases are generated so that there will be an answer.
# 
#Example 1:
#Input: nums = [1,2,5,9], threshold = 6
#Output: 5
#Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
#If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
#Example 2:
#Input: nums = [44,22,33,11,1], threshold = 5
#Output: 44
# 
#Constraints:
#	1 <= nums.length <= 5 * 104
#	1 <= nums[i] <= 106
#	nums.length <= threshold <= 106
class Solution(object):
    def smallestDivisor(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        # Approach 1: Binary Search
		# Time Complexity: O(Nlog(N))
		# Space Complexity: O(1)
		# Runtime: 388 ms, faster than 68.48% of Python online submissions for Find the Smallest Divisor Given a Threshold.
		# Memory Usage: 14.2 MB, less than 100.00% of Python online submissions for Find the Smallest Divisor Given a Threshold.
        left, right = 1, max(nums)
        while left <= right:
            mid = left + (right - left) // 2
            if sum((num - 1) // mid + 1 for num in nums) > threshold:
                left = mid + 1
            else:
                right = mid - 1
        return left