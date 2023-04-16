#https://leetcode.com/problems/valid-parentheses/
#Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#An input string is valid if:
#Open brackets must be closed by the same type of brackets.
#Open brackets must be closed in the correct order.
#Every close bracket has a corresponding open bracket of the same type.


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s)==0:
            return True
        elif len(s)%2==1:
            return False
        else:
            stack=[]
            for i in range(0,len(s)):
                if s[i]=='(' or s[i]=='[' or s[i]=='{':
                    stack.append(s[i])
                else:
                    if len(stack)==0:
                        return False
                    elif s[i]==')' and stack[len(stack)-1]=='(':
                        stack.pop()
                    elif s[i]==']' and stack[len(stack)-1]=='[':
                        stack.pop()
                    elif s[i]=='}' and stack[len(stack)-1]=='{':
                        stack.pop()
                    else:
                        return False
            if len(stack)==0:
                return True
            else:
                return False

    