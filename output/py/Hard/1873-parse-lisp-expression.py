#https://leetcode.com/problems/parse-lisp-expression/
#You are given a string expression representing a Lisp-like expression to return the integer value of.
#The syntax for these expressions is given as follows.
#An expression is either an integer, let expression, add expression, mult expression, or an assigned variable. Expressions always evaluate to a single integer.
#(An integer could be positive or negative.)
#A let expression takes the form "(let v1 e1 v2 e2 ... vn en expr)", where let is always the string "let", then there are one or more pairs of alternating variables and expressions, meaning that the first variable v1 is assigned the value of the expression e1, the second variable v2 is assigned the value of the expression e2, and so on sequentially; and then the value of this let expression is the value of the expression expr.
#An add expression takes the form "(add e1 e2)" where add is always the string "add", there are always two expressions e1, e2 and the result is the addition of the evaluation of e1 and the evaluation of e2.
#A mult expression takes the form "(mult e1 e2)" where mult is always the string "mult", there are always two expressions e1, e2 and the result is the multiplication of the evaluation of e1 and the evaluation of e2.
#For this question, we will use a smaller subset of variable names. A variable starts with a lowercase letter, then zero or more lowercase letters or digits. Additionally, for your convenience, the names "add", "let", and "mult" are protected and will never be used as variable names.
#Finally, there is the concept of scope. When an expression of a variable name is evaluated, within the context of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially. It is guaranteed that every expression is legal. Please see the examples for more details on the scope.


class Solution(object):
    def evaluate(self, expression):
        """
        :type expression: str
        :rtype: int
        """    
        #print(expression)
        #print(expression[0])
        if expression[0] == '(':
            #print(expression[1:4])
            if expression[1:4] == 'let':
                return self.let(expression[5:-1])
            elif expression[1:4] == 'add':
                return self.add(expression[5:-1])
            elif expression[1:4] == 'mul':
                return self.mul(expression[5:-1])
        else:
            return self.var(expression)


  


        
        
    