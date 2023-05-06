#https://leetcode.com/problems/max-consecutive-ones/
#Given a binary array nums, return the maximum number of consecutive 1's in the array.


class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """ 
        res=0
        count=0
        for i in range(len(nums)):
            if nums[i]==1:
                count=count+1
            else:
                res=max(res,count)
                count=0
        res=max(res,count)
        return res

    