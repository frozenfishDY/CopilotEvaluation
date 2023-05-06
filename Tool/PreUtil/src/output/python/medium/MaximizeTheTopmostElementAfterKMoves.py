#https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/
#You are given a 0-indexed integer array nums representing the contents of a pile, where nums[0] is the topmost element of the pile.
#In one move, you can perform either of the following:
#If the pile is not empty, remove the topmost element of the pile.
#If there are one or more removed elements, add any one of them back onto the pile. This element becomes the new topmost element.
#You are also given an integer k, which denotes the total number of moves to be made.
#Return the maximum value of the topmost element of the pile possible after exactly k moves. In case it is not possible to obtain a non-empty pile after k moves, return -1.


class Solution(object):
    def maximumTop(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result=0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)+1):
                if len(set([nums[k]+c for k in range(i,j) for c in range(k+1)]))==len([nums[k]+c for k in range(i,j) for c in range(k+1)]):
                    result=max(result,min(nums[i:j]))
        return result
        

    