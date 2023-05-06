#https://leetcode.com/problems/number-of-ways-to-split-array/
#You are given a 0-indexed integer array nums of length n.
#nums contains a valid split at index i if the following are true:
#The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
#There is at least one element to the right of i. That is, 0 <= i < n - 1.
#Return the number of valid splits in nums.


class Solution(object):
    def waysToSplitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """      
        result=0
        for i in range(len(nums)-2):
            left=nums[:i+1]
            right=nums[i+1:]
            if sum(left)>=sum(right):
                break
            else:
                for j in range(len(right)-1):
                    if sum(left)<=sum(right[:j+1]):
                        break
                    else:
                        result+=1
        return result

        
    