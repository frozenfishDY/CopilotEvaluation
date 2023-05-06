#https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
#You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
#Return the rearranged number with minimal value.
#Note that the sign of the number does not change after rearranging the digits.


class Solution(object):
    def smallestNumber(self, num):
        """
        :type num: int
        :rtype: int
        """
        # 1. Convert the number to a list of digits
        # 2. Sort the list
        # 3. Convert the list to a number
        # 4. If the number is 0, then return 0
        # 5. If the number is not 0, then return the number
        digits = self.convert_number_to_list_of_digits(num)
        digits.sort()
        number = self.convert_list_of_digits_to_number(digits)
        if number == 0:
            return 0
        return number
        

    