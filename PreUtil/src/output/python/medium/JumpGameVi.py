#https://leetcode.com/problems/jump-game-vi/
#You are given a 0-indexed integer array nums and an integer k.
#You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.
#You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.
#Return the maximum score you can get.


class Solution(object):
    def maxResult(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result=0
        for i in range(len(nums)):
            for j in range(i+1,min(len(nums),i+k)+1):
                if len(set(nums[i:j]))==len(nums[i:j]):
                    result=max(result,sum(nums[i:j]))
        return result
        

    