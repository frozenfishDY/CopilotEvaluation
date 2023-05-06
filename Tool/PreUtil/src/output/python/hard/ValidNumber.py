#https://leetcode.com/problems/valid-number/
#A valid number can be split up into these components (in order):
#A decimal number or an integer.
#(Optional) An 'e' or 'E', followed by an integer.
#A decimal number can be split up into these components (in order):
#(Optional) A sign character (either '+' or '-').
#One of the following formats:
#One or more digits, followed by a dot '.'.
#One or more digits, followed by a dot '.', followed by one or more digits.
#A dot '.', followed by one or more digits.
#An integer can be split up into these components (in order):
#(Optional) A sign character (either '+' or '-').
#One or more digits.
#For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
#Given a string s, return true if s is a valid number.


class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """       
        # remove the leading and trailing spaces
        s = s.strip()
        # check if the string is empty
        if not s:
            return False
        # check if the string is a valid number
        if self.is_valid_number(s):
            return True
        # check if the string is a valid number with exponent
        if self.is_valid_number_with_exponent(s):
            return True
        # check if the string is a valid number with decimal
        if self.is_valid_number_with_decimal(s):
            return True
        # check if the string is a valid number with decimal and exponent
        if self.is_valid_number_with_decimal_and_exponent(s):
            return True
        # if none of the above conditions are true, then the string is not a valid number
        return False
       
    