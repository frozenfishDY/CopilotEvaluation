#https://leetcode.com/problems/four-divisors/
#Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.


class Solution(object):
    def sumFourDivisors(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """      
        
        # 1. Loop through the list
        # 2. For each number, get the divisors
        # 3. If the number of divisors is 4, then add the sum of the divisors to the result
        # 4. Return the result
        result = 0
        for num in nums:
            divisors = self.get_divisors(num)
            if len(divisors) == 4:
                result += sum(divisors)
        return result

        

    