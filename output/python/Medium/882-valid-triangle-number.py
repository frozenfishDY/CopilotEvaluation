#https://leetcode.com/problems/valid-triangle-number/
#Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
# 
#Example 1:
#Input: nums = [2,2,3,4]
#Output: 3
#Explanation: Valid combinations are: 
#2,3,4 (using the first 2)
#2,3,4 (using the second 2)
#2,2,3
#Example 2:
#Input: nums = [4,2,3,4]
#Output: 4
# 
#Constraints:
#	1 <= nums.length <= 1000
#	0 <= nums[i] <= 1000
class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #Solution
        #1. Sort the nums in ascending order
        #2. For each number in nums, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #nums: [2,2,3,4]
        #ret: 3
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = 0
        nums.sort()
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                for k in range(j + 1, len(nums)):
                    if nums[i] + nums[j] > nums[k]:
                        ret += 1

        return ret