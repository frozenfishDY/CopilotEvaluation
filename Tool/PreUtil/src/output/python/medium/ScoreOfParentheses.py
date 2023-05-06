#https://leetcode.com/problems/score-of-parentheses/
#Given a balanced parentheses string s, return the score of the string.
#The score of a balanced parentheses string is based on the following rule:
#"()" has score 1.
#AB has score A + B, where A and B are balanced parentheses strings.
#(A) has score 2 * A, where A is a balanced parentheses string.


class Solution(object):
    def scoreOfParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        for c in s:
            if c == '(':
                stack.append(c)
            else:
                if stack[-1] == '(':
                    stack.pop()
                    stack.append(1)
                else:
                    temp = 0
                    while stack[-1] != '(':
                        temp += stack.pop()
                    stack.pop()
                    stack.append(2 * temp)
        return sum(stack)
        

    