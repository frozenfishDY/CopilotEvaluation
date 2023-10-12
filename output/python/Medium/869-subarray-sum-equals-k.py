#https://leetcode.com/problems/subarray-sum-equals-k/
#Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
#A subarray is a contiguous non-empty sequence of elements within an array.
# 
#Example 1:
#Input: nums = [1,1,1], k = 2
#Output: 2
#Example 2:
#Input: nums = [1,2,3], k = 3
#Output: 2
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	-1000 <= nums[i] <= 1000
#	-107 <= k <= 107
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #Solution
        #1. For each number in nums, add the number to the sum
        #2. If the sum is equal to k, add 1 to the result
        #3. Return the result
        #
        #Example:
        #nums: [1,1,1]
        #k: 2
        #ret: 2
        #
        #Time complexity: O(n)
        #Space complexity: O(n)

        result = 0
        sum = 0
        sum_map = {0:1}
        for num in nums:
            sum += num
            result += sum_map.get(sum - k, 0)
            sum_map[sum] = sum_map.get(sum, 0) + 1

        return result