#https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
#You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.
#The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.
#Return the minimum number of moves required to make nums complementary.


class Solution(object):
    def minMoves(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        if len(nums)==2:
            return min(nums[0],nums[1])
        if len(nums)==4:
            return min(nums[0]+nums[1],nums[2]+nums[3])
        if nums[0]+nums[-1]==limit:
            return self.minMoves(nums[1:-1],limit)
        else:
            return min(nums[0]+nums[-1]+self.minMoves(nums[1:-1],limit),limit+self.minMoves(nums[1:-1],limit))
        

    