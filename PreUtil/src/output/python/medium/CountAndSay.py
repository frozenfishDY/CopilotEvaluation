#https://leetcode.com/problems/count-and-say/
#The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
#countAndSay(1) = "1"
#countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
#To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.
#For example, the saying and conversion for digit string "3322251":
# 


class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """  
        if n==1:
            return "1"
        res = "1"
        for i in range(n-1):
            res = self.helper(res)
        return res

        

    