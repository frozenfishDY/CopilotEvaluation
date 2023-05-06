#https://leetcode.com/problems/sliding-window-maximum/
#You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
#Return the max sliding window.


class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """       
        if not nums:
            return []
        if k==1:
            return nums
        result=[]
        for i in range(len(nums)-k+1):
            result.append(max(nums[i:i+k]))
        return result

        
        
    