#https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
#A parentheses string is valid if and only if:
#It is the empty string,
#It can be written as AB (A concatenated with B), where A and B are valid strings, or
#It can be written as (A), where A is a valid string.
#You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
#For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
#Return the minimum number of moves required to make s valid.


class Solution(object):
    def minAddToMakeValid(self, s):
        """
        :type s: str
        :rtype: int
        """                    
        res = 0
        left = 0
        for i in range(len(s)):
            if s[i] == "(":
                left += 1
            else:
                if left == 0:
                    res += 1
                else:
                    left -= 1
        return res + left

        

    