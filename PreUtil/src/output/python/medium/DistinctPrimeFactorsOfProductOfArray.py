#https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/
#Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.
#Note that:
#A number greater than 1 is called prime if it is divisible by only 1 and itself.
#An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.


class Solution(object):
    def distinctPrimeFactors(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                res += self.gcd(nums[i],nums[j])
        return res
        

    