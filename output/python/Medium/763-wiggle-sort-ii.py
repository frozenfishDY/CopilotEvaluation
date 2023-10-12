#https://leetcode.com/problems/wiggle-sort-ii/
#Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
#You may assume the input array always has a valid answer.
# 
#Example 1:
#Input: nums = [1,5,1,1,6,4]
#Output: [1,6,1,5,1,4]
#Explanation: [1,4,1,5,1,6] is also accepted.
#Example 2:
#Input: nums = [1,3,2,2,3,1]
#Output: [2,3,1,3,1,2]
# 
#Constraints:
#	1 <= nums.length <= 5 * 104
#	0 <= nums[i] <= 5000
#	It is guaranteed that there will be an answer for the given input nums.
# 
#Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # 1. sort and divide into 2 groups
        nums.sort()
        n = len(nums)
        a = nums[:(n + 1) // 2]
        b = nums[(n + 1) // 2:]
        # 2. reverse a
        a = a[::-1]
        # 3. interleave
        for i in range(n):
            if i % 2 == 0:
                nums[i] = a[i // 2]
            else:
                nums[i] = b[i // 2]