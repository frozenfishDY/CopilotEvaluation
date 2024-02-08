#https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
#Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
#If the current number is even, you have to divide it by 2.
#If the current number is odd, you have to add 1 to it.
#It is guaranteed that you can always reach one for all test cases.


class Solution(object):
    def numSteps(self, s):
        """
        :type s: str
        :rtype: int
        """     
        
        # 1. Convert the string to an integer
        # 2. Loop until the number is 1
        # 3. If the number is even, divide it by 2
        # 4. If the number is odd, add 1 to it
        # 5. Increment the result by 1
        # 6. Return the result
        num = int(s, 2)
        result = 0
        while num != 1:
            if num % 2 == 0:
                num /= 2
            else:
                num += 1
            result += 1
        return result

        

    