#https://leetcode.com/problems/contiguous-array/
#Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
# 
#Example 1:
#Input: nums = [0,1]
#Output: 2
#Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
#Example 2:
#Input: nums = [0,1,0]
#Output: 2
#Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
# 
#Constraints:
#	1 <= nums.length <= 105
#	nums[i] is either 0 or 1.
class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in nums, add 1 to the sum if the number is 1, otherwise subtract 1
        #3. If the sum is 0, set the result to the current index + 1
        #4. If the sum is already in the hashmap, set the result to the max of the current index and the hashmap value
        #5. Return the result
        #
        #Example:
        #nums: [0,1,0]
        #ret: 2
        #
        #Time complexity: O(n)
        #Space complexity: O(n)

        result = 0
        hashmap = {0: -1}
        sum = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                sum += 1
            else:
                sum -= 1
            if sum == 0:
                result = i + 1
            if sum in hashmap:
                result = max(result, i - hashmap[sum])
            else:
                hashmap[sum] = i

        return result