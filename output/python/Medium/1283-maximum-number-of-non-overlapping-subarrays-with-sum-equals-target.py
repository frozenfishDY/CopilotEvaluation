#https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
#Given an array nums and an integer target, return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.
# 
#Example 1:
#Input: nums = [1,1,1,1,1], target = 2
#Output: 2
#Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
#Example 2:
#Input: nums = [-1,3,5,1,4,2,-9], target = 6
#Output: 2
#Explanation: There are 3 subarrays with sum equal to 6.
#([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
# 
#Constraints:
#	1 <= nums.length <= 105
#	-104 <= nums[i] <= 104
#	0 <= target <= 106
class Solution(object):
    def maxNonOverlapping(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res = 0
        cur = 0
        visited = set()
        visited.add(0)
        for num in nums:
            cur += num
            if cur - target in visited:
                res += 1
                visited = set()
            visited.add(cur)
        return res