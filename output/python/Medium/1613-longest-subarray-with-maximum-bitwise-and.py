#https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
#You are given an integer array nums of size n.
#Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
#	In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
#Return the length of the longest such subarray.
#The bitwise AND of an array is the bitwise AND of all the numbers in it.
#A subarray is a contiguous sequence of elements within an array.
# 
#Example 1:
#Input: nums = [1,2,3,3,2,2]
#Output: 2
#Explanation:
#The maximum possible bitwise AND of a subarray is 3.
#The longest subarray with that value is [3,3], so we return 2.
#Example 2:
#Input: nums = [1,2,3,4]
#Output: 1
#Explanation:
#The maximum possible bitwise AND of a subarray is 4.
#The longest subarray with that value is [4], so we return 1.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 106
class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. Get the max bit length of the array
        max_bit_length = 0
        for num in nums:
            max_bit_length = max(max_bit_length, len(bin(num)) - 2)

        # 2. Get the max bit length of the max bitwise AND of the array
        max_bit_length_of_max_bitwise_and = 0
        for num in nums:
            if num & (num - 1) == 0:
                max_bit_length_of_max_bitwise_and = max(max_bit_length_of_max_bitwise_and, len(bin(num)) - 2)

        # 3. Get the max length of the subarray with max bitwise AND
        max_length = 0
        for i in range(len(nums)):
            if nums[i] & (nums[i] - 1) == 0:
                max_length = max(max_length, 1)
            else:
                max_length = max(max_length, self.get_max_length_of_subarray_with_max_bitwise_and(nums, i, max_bit_length_of_max_bitwise_and))

        return max_length