#https://leetcode.com/problems/simplified-fractions/
#Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.


class Solution(object):
    def simplifiedFractions(self, n):
        """
        :type n: int
        :rtype: List[str]
        """        
        # 1. Loop through the numbers from 2 to n
        # 2. Loop through the numbers from 1 to n
        # 3. If the number is less than the current number, then add the fraction to the result
        # 4. Return the result
        result = []
        for i in range(2, n + 1):
            for j in range(1, i):
                if self.is_coprime(j, i):
                    result.append(str(j) + "/" + str(i))
        return result
       

        

    