#https://leetcode.com/problems/minimize-maximum-of-array/
#You are given a 0-indexed array nums comprising of n non-negative integers.
#In one operation, you must:
#Choose an integer i such that 1 <= i < n and nums[i] > 0.
#Decrease nums[i] by 1.
#Increase nums[i - 1] by 1.
#Return the minimum possible value of the maximum integer of nums after performing any number of operations.


class Solution(object):
    def minimizeArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=0
        while len(nums)>0:
            if len(set(nums))==1:
                result+=1
                nums=[]
            else:
                for i in range(len(nums)):
                    if nums[i]%2==1:
                        nums[i]+=1
                nums=[nums[i]//2 for i in range(len(nums))]
                result+=1
        return result
        
    