#https://leetcode.com/problems/longest-valid-parentheses/
#Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.


class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        res=0
        stack=[-1]
        for i in range(len(s)):
            if s[i]=='(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    res=max(res,i-stack[-1])
        return res
        
    