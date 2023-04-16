#https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
#A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
#It is ().
#It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
#It can be written as (A), where A is a valid parentheses string.
#You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
#If locked[i] is '1', you cannot change s[i].
#But if locked[i] is '0', you can change s[i] to either '(' or ')'.
#Return true if you can make s a valid parentheses string. Otherwise, return false.


class Solution(object):
    def canBeValid(self, s, locked):
        """
        :type s: str
        :type locked: str
        :rtype: bool
        """ 
        stack=[]
        for i in range(len(s)):
            if locked[i]=='0':
                if s[i]=='(':
                    stack.append(s[i])
                else:
                    if len(stack)>0:
                        stack.pop()
                    else:
                        return False
            else:
                if s[i]==')':
                    if len(stack)>0:
                        stack.pop()
                    else:
                        return False
        return len(stack)==0
        

    