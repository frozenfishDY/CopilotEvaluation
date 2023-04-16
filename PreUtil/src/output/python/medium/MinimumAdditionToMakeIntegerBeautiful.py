#https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/
#You are given two positive integers n and target.
#An integer is considered beautiful if the sum of its digits is less than or equal to target.
#Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.


class Solution(object):
    def makeIntegerBeautiful(self, n, target):
        """
        :type n: int
        :type target: int
        :rtype: int
        """      
        # 1. Get the sum of the digits
        # 2. If the sum is greater than the target, then return the difference
        # 3. If the sum is less than or equal to the target, then return 0
        sum_digits = self.get_sum_of_digits(n)
        if sum_digits > target:
            return sum_digits - target
        return 0
        

    