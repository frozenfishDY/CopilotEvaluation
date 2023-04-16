#https://leetcode.com/problems/evaluate-reverse-polish-notation/
#You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
#Evaluate the expression. Return an integer that represents the value of the expression.


class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """       
        stack = []
        for i in tokens:
            if i not in ["+","-","*","/"]:
                stack.append(int(i))
            else:
                a = stack.pop()
                b = stack.pop()
                if i == "+":
                    stack.append(a+b)
                elif i == "-":
                    stack.append(b-a)
                elif i == "*":
                    stack.append(a*b)
                else:
                    stack.append(int(float(b)/a))
        return stack[0]

        

    