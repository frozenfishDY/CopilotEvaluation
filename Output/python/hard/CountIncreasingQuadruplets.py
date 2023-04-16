#https://leetcode.com/problems/count-increasing-quadruplets/
#Given a 0-indexed integer array nums of size n containing all numbers from 1 to n, return the number of increasing quadruplets.
#A quadruplet (i, j, k, l) is increasing if:
#0 <= i < j < k < l < n, and
#nums[i] < nums[k] < nums[j] < nums[l].


class Solution(object):
    def countQuadruplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """       
        if not nums:
            return 0
        result=0
        for i in range(len(nums)-3):
            for j in range(i+1,len(nums)-2):
                for k in range(j+1,len(nums)-1):
                    for l in range(k+1,len(nums)):
                        if nums[i]<nums[k]<nums[j]<nums[l]:
                            result+=1
        return result
            
            
        
        
    