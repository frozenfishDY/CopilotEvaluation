#https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
#Return the shortest such subarray and output its length.
# 
#Example 1:
#Input: nums = [2,6,4,8,10,9,15]
#Output: 5
#Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
#Example 2:
#Input: nums = [1,2,3,4]
#Output: 0
#Example 3:
#Input: nums = [1]
#Output: 0
# 
#Constraints:
#	1 <= nums.length <= 104
#	-105 <= nums[i] <= 105
# 
#Follow up: Can you solve it in O(n) time complexity?
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #Solution
        #1. Initialize the result to -1
        #2. For each number in nums, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #nums: [2,6,4,8,10,9,15]
        #ret: 5
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = [-1] * len(nums)
        for num in nums:
            for i in range(len(ret)):
                if num > ret[i]:
                    ret[i] = num

        return ret