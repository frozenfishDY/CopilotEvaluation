#https://leetcode.com/problems/basic-calculator/
#Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
#Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        stack = []
        num = 0
        sign = '+'
        for i in range(len(s)):
            if s[i].isdigit():
                num = num * 10 + int(s[i])
            if (not s[i].isdigit() and not s[i].isspace()) or i == len(s) - 1:
                if sign == '-':
                    stack.append(-num)
                elif sign == '+':
                    stack.append(num)
                elif sign == '*':
                    stack.append(stack.pop() * num)
                elif sign == '/':
                    stack.append(int(stack.pop() / float(num)))
                sign = s[i]
                num = 0
        return sum(stack)
        
        
    