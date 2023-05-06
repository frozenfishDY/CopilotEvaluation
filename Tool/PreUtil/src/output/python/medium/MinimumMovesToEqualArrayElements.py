#https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
#Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
#In one move, you can increment n - 1 elements of the array by 1.


class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                res += self.gcd(nums[i],nums[j])
        return res
        

    