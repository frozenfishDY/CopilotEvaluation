#https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
#Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
# 
#Example 1:
#Input: nums = [4,3,2,3,5,2,1], k = 4
#Output: true
#Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
#Example 2:
#Input: nums = [1,2,3,4], k = 3
#Output: false
# 
#Constraints:
#	1 <= k <= nums.length <= 16
#	1 <= nums[i] <= 104
#	The frequency of each element is in the range [1, 4].
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in nums, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #nums: [4,3,2,3,5,2,1], k = 4
        #ret: true
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = 0
        for i in range(len(nums)):
            for j in range(len(nums[i])):
                if nums[i][j] == 1:
                    if self.check(nums, i, j):
                        ret += 1
        return ret