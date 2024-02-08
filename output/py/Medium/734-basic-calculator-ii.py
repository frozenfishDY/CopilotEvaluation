#https://leetcode.com/problems/basic-calculator-ii/
#Given a string s which represents an expression, evaluate this expression and return its value. 
#The integer division should truncate toward zero.
#You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
#Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """       
        s = s.replace(" ","")
        stack = []
        num = 0
        sign = "+"
        for i in range(len(s)):
            if s[i].isdigit():
                num = num*10 + int(s[i])
            if i == len(s)-1 or s[i] in "+-*/":
                if sign == "+":
                    stack.append(num)
                elif sign == "-":
                    stack.append(-num)
                elif sign == "*":
                    stack.append(stack.pop()*num)
                elif sign == "/":
                    stack.append(int(stack.pop()/float(num)))
                sign = s[i]
                num = 0
        return sum(stack)
        

    