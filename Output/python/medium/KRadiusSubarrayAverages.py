#https://leetcode.com/problems/k-radius-subarray-averages/
#You are given a 0-indexed array nums of n integers, and an integer k.
#The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.
#Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.
#The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.
#For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.


class Solution(object):
    def getAverages(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """       
        result=[]
        for i in range(len(nums)):
            if i-k<0:
                left=0
            else:
                left=i-k
            if i+k>len(nums)-1:
                right=len(nums)-1
            else:
                right=i+k
            if right-left<k*2:
                result.append(-1)
            else:
                result.append(sum(nums[left:right+1])/(right-left+1))
        return result

        

    