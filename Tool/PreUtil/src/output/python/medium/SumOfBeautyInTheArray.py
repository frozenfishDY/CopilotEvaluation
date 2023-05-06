#https://leetcode.com/problems/sum-of-beauty-in-the-array/
#You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:
#2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
#1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
#0, if none of the previous conditions holds.
#Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.


class Solution(object):
    def sumOfBeauties(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """      
        result=0
        for i in range(1,len(nums)-1):
            if nums[i-1]<nums[i]<nums[i+1]:
                result+=1
            elif nums[i-1]<nums[i] and nums[i]<nums[i+1]:
                result+=2
        return result

        

    