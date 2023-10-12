#https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
# 
#Example 1:
#Input: nums = [3,10,5,25,2,8]
#Output: 28
#Explanation: The maximum result is 5 XOR 25 = 28.
#Example 2:
#Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
#Output: 127
# 
#Constraints:
#	1 <= nums.length <= 2 * 105
#	0 <= nums[i] <= 231 - 1
class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #Solution
        #1. Initialize the maximum result to 0
        #2. Iterate through every bit in nums
        #3. For each bit, check if there is a pair of numbers in nums that the bit is different
        #   If there is, update the maximum result
        #4. Return the maximum result
        #
        #Example:
        #nums: [3,10,5,25,2,8]
        #maxResult: 0
        #bit: 1
        #maxResult: 0
        #bit: 2
        #maxResult: 3
        #bit: 4
        #maxResult: 7
        #bit: 8
        #maxResult: 31
        #bit: 16
        #maxResult: 31
        #bit: 32
        #maxResult: 31
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        maxResult = 0
        mask = 0
        for i in range(31, -1, -1):
            mask = mask | (1 << i)
            s = set()
            for num in nums:
                s.add(num & mask)

            temp = maxResult | (1 << i)
            for prefix in s:
                if temp ^ prefix in s:
                    maxResult = temp
                    break

        return maxResult