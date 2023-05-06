#https://leetcode.com/problems/chalkboard-xor-game/
#You are given an array of integers nums represents the numbers written on a chalkboard.
#Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first. If erasing a number causes the bitwise XOR of all the elements of the chalkboard to become 0, then that player loses. The bitwise XOR of one element is that element itself, and the bitwise XOR of no elements is 0.
#Also, if any player starts their turn with the bitwise XOR of all the elements of the chalkboard equal to 0, then that player wins.
#Return true if and only if Alice wins the game, assuming both players play optimally.


class Solution(object):
    def xorGame(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums)%2==0:
            return True
        result=nums[0]
        for i in range(1,len(nums)):
            result=result^nums[i]
        return result==0
        
        
    