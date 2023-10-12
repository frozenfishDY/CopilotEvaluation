#https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
#Given a string s of '(' , ')' and lowercase English characters.
#Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
#Formally, a parentheses string is valid if and only if:
#	It is the empty string, contains only lowercase characters, or
#	It can be written as AB (A concatenated with B), where A and B are valid strings, or
#	It can be written as (A), where A is a valid string.
# 
#Example 1:
#Input: s = "lee(t(c)o)de)"
#Output: "lee(t(c)o)de"
#Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
#Example 2:
#Input: s = "a)b(c)d"
#Output: "ab(c)d"
#Example 3:
#Input: s = "))(("
#Output: ""
#Explanation: An empty string is also valid.
# 
#Constraints:
#	1 <= s.length <= 105
#	s[i] is either'(' , ')', or lowercase English letter.
class Solution(object):
    def minRemoveToMakeValid(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Approach 1: Stack
		# Time Complexity: O(N)
		# Space Complexity: O(N)
		# Runtime: 68 ms, faster than 93.96% of Python online submissions for Minimum Remove to Make Valid Parentheses.
		# Memory Usage: 13.8 MB, less than 16.67% of Python online submissions for Minimum Remove to Make Valid Parentheses.
        stack, s = [], list(s)
        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)
            elif c == ')':
                if stack:
                    stack.pop()
                else:
                    s[i] = ''
        while stack:
            s[stack.pop()] = ''
        return ''.join(s)