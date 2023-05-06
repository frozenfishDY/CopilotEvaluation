#https://leetcode.com/problems/single-number-ii/
#Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
#You must implement a solution with a linear runtime complexity and use only constant extra space.


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """      
        res = 0
        for i in range(32):
            sum = 0
            for num in nums:
                if num>>i & 1:
                    sum+=1
            sum %= 3
            if sum:
                res |= sum<<i
        return res if res < 2**31 else ~(res^0xffffffff)

        

    