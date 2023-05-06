#https://leetcode.com/problems/degree-of-an-array/
#Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
#Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.


class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_count=0
        min_length=0
        dict={}
        for i in range(len(nums)):
            if nums[i] in dict:
                dict[nums[i]][0]+=1
                dict[nums[i]][2]=i
            else:
                dict[nums[i]]=[1,i,i]
        for key in dict:
            if dict[key][0]>max_count:
                max_count=dict[key][0]
                min_length=dict[key][2]-dict[key][1]+1
            elif dict[key][0]==max_count:
                min_length=min(min_length,dict[key][2]-dict[key][1]+1)
        return min_length
        

    