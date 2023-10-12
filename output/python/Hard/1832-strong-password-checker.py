#https://leetcode.com/problems/strong-password-checker/
#A password is considered strong if the below conditions are all met:
#	It has at least 6 characters and at most 20 characters.
#	It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
#	It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
#Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.
#In one step, you can:
#	Insert one character to password,
#	Delete one character from password, or
#	Replace one character of password with another character.
# 
#Example 1:
#Input: password = "a"
#Output: 5
#Example 2:
#Input: password = "aA1"
#Output: 3
#Example 3:
#Input: password = "1337C0d3"
#Output: 0
# 
#Constraints:
#	1 <= password.length <= 50
#	password consists of letters, digits, dot '.' or exclamation mark '!'.
class Solution(object):
    def strongPasswordChecker(self, password):
        """
        :type password: str
        :rtype: int
        """
         #https://leetcode.com/problems/strong-password-checker/discuss/91008/Simple-Python-solution
        count = [0, 0, 0]
        for c in password:
            if c.islower():
                count[0] = 1
            elif c.isupper():
                count[1] = 1
            elif c.isdigit():
                count[2] = 1
        missing = sum(count)
        change = 0
        one = two = 0
        i = 2
        while i < len(password):
            if password[i] == password[i - 1] == password[i - 2]:
                length = 2
                while i < len(password) and password[i] == password[i - 1]:
                    length += 1
                    i += 1
                change += length / 3
                if length % 3 == 0:
                    one += 1
                elif length % 3 == 1:
                    two += 1
            else:
                i += 1
        if len(password) < 6:
            return max(6 - len(password), missing)
        elif len(password) <= 20:
            return max(change, missing)
        else:
            delete = len(password) - 20
            change -= min(delete, one)
            change -= min(max(delete - one, 0), two * 2) / 2
            change -= max(delete - one - 2 * two, 0) / 3
            return delete + max(change, missing)