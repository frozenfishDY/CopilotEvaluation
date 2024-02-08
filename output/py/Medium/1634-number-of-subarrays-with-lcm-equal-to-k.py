#https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/
#Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.
#A subarray is a contiguous non-empty sequence of elements within an array.
#The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.
# 
#Example 1:
#Input: nums = [3,6,2,7,1], k = 6
#Output: 4
#Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
#- [3,6,2,7,1]
#- [3,6,2,7,1]
#- [3,6,2,7,1]
#- [3,6,2,7,1]
#Example 2:
#Input: nums = [3], k = 2
#Output: 0
#Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.


class Solution(object):
    def subarrayLCM(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """       
        if k==1:
            return len(nums)*(len(nums)+1)/2
        if k>max(nums):
            return 0
        if k==max(nums):
            return 1
        #...
        if k==2:
            return sum([1 for i in nums if i%2==0])
        if k==3:
            return sum([1 for i in nums if i%3==0])
        if k==5:
            return sum([1 for i in nums if i%5==0])
        if k==7:
            return sum([1 for i in nums if i%7==0])
        if k==11:
            return sum([1 for i in nums if i%11==0])
        if k==13:
            return sum([1 for i in nums if i%13==0])
        if k==17:
            return sum([1 for i in nums if i%17==0])
        if k==19:
            return sum([1 for i in nums if i%19==0])
        if k==23:
            return sum([1 for i in nums if i%23==0])
        if k==29:
            return sum([1 for i in nums if i%29==0])
        #...
        if k==31:
            return sum([1 for i in nums if i%31==0])
        if k==37:
            return sum([1 for i in nums if i%37==0])
        if k==41:
            return sum([1 for i in nums if i%41==0])
        if k==43:
            return sum([1 for i in nums if i%43==0])
        if k==47:
            return sum([1 for i in nums if i%47==0])
        if k==53:
            return sum([1 for i in nums if i%53==0])
        if k==59:
            return sum([1 for i in nums if i%59==0])
        if k==61:
            return sum([1 for i in nums if i%61==0])
        if k==67:
            return sum([1 for i in nums if i%67==0])
        if k==71:
            return sum([1 for i in nums if i%71==0])
        if k==73:
            return sum([1 for i in nums if i % 73 == 0])

        

    